#include <ata.h>
#include <port.h>
#include <interrupt.h>
#include <pic.h>
#include <screen.h>
#include <tasks.h>

static TCB *waitingTask;

static uint_16 *readBuffer;
static size_t readBufferIndex;

static uint_8 sectorsToRead;

static Mutex ataMutex;

void readSector();
void readSector(uint_16 *buffer);

void identifyDrive() {
    lockScheduler();

    uint_16 sector[256];
    readBuffer = sector;
    readBufferIndex = 0;
    sectorsToRead = 1;

    portByteOut(SECTOR_COUNT_REG, 0);
    portByteOut(LBA_LOW_REG, 0);
    portByteOut(LBA_MID_REG, 0);
    portByteOut(LBA_HIGH_REG, 0);
 
    portByteOut(COMMAND_REG, IDENTIFY_CMD);
    
    // 400ns
    for (int i = 0; i < 4; i++) portByteIn(ALT_STATUS_REG);

    uint_8 status;
    while (status = portByteIn(ALT_STATUS_REG) & Status::BSY && !(status & Status::ERR));

    if (status == 0) {
        println("Drive doesn't exist.");
        return;
    }
    else if (status & Status::ERR == 1) {
        uint_8 errVal1 = portByteIn(LBA_MID_REG);
        uint_8 errVal2 = portByteIn(LBA_HIGH_REG);
        if (errVal1 == 0x14 && errVal2 == 0xEB) {
            println("Error identifying ATA device: Detected an ATAPI device.");
        }
        else if (errVal1 == 0x3C && errVal2 == 0xC3) {
            println("Error identifying ATA device: Detected a SATA device.");
        }
        else if (errVal1 == 0 && errVal2 == 0) {
            println("Error identifying ATA device: ATA identify abort.");
        }
        else {
            println("Error identifying ATA device.");
        }

        print("ERROR ");
        printHex(portByteIn(ERROR_REG));
        println();

        unlockScheduler();
        return;
    }
    
    waitingTask = getCurrentTask();
    blockTask();

    unlockScheduler();
}

void read(uint_32 lbaBlock, uint_8 sectorCount, uint_8 *buffer) {
    ataMutex.wait();

    readBuffer = (uint_16*)buffer;
    readBufferIndex = 0;
    sectorsToRead = sectorCount;

    while (portByteIn(ALT_STATUS_REG) & Status::BSY);

    portByteOut(FEATURES_REG, 0x00);

    portByteOut(LBA_LOW_REG, lbaBlock & 0xFF);
    portByteOut(LBA_MID_REG, ((lbaBlock >> 8) & 0xFF));
    portByteOut(LBA_HIGH_REG, ((lbaBlock >> 16)) & 0xFF);
    // always set (1), LBA Addressing (1), always set (1), master drive number (0), bits 24-27 of LBA block
    uint_8 driveAddrRegVal = 0b11100000 | ((lbaBlock >> 24) & 0x0F); 
    portByteOut(DRIVE_REG, driveAddrRegVal);
    portByteOut(SECTOR_COUNT_REG, sectorCount);

    portByteOut(COMMAND_REG, READ_SECTORS_WITH_RETRY_CMD);

    waitingTask = getCurrentTask();
    blockTask();

    ataMutex.release();
}

void readSector(uint_16 *buffer) {
    for (int i = 0; i < 256; i++) {
        buffer[i] = portWordIn(DATA_REG);
    }
}

void readSector() {
    readSector(readBuffer + readBufferIndex);
    readBufferIndex += 256;
}

void driveISR(InterruptFrame *frame) {
    uint_8 status = portByteIn(STATUS_REG);

    if (status & Status::BSY) return;

    if (status & Status::ERR || status & Status::DF) {
        print("Drive Error");
    }

    if (status & Status::DRQ && sectorsToRead > 0) {
        readSector();

        sectorsToRead--;

        if (sectorsToRead == 0) {
            unblockTask(waitingTask);
        }
    }

    sendEOI(true);
}

void initAta() {
    ataMutex = Mutex();

    uint_8 status = portByteIn(ALT_STATUS_REG);
    if (status == 0xFF) {
        println("Floating bus.");
        return;
    }

    portByteOut(DRIVE_REG, 0xE0); // always set (1), LBA Addressing (1), always set (1), master drive number (0)
    
    registerInterrupt(0x2E, driveISR, Gate::interrupt); // 14 for primary ATA Hard Disk
    portByteOut(DEV_CONTROL_REG, (portByteIn(DEV_CONTROL_REG) & ~(0x02))); // clear nIEN to enable interrupts
}