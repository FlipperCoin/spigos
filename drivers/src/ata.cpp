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
static bool identify;

void read(uint_32 lbaBlock, uint_8 sectorCount, uint_8 *buffer) {
    lockScheduler();

    readBuffer = (uint_16*)buffer;
    readBufferIndex = 0;
    sectorsToRead = sectorCount;

    portByteOut(FEATURES_REG, 0x00);

    portByteOut(LBA_LOW_REG, lbaBlock & 0xFF);
    portByteOut(LBA_MID_REG, ((lbaBlock >> 8) & 0xFF));
    portByteOut(LBA_HIGH_REG, ((lbaBlock >> 16)) & 0xFF);
    // always set (1), LBA Addressing (1), always set (1), drive number (0), bits 24-27 of LBA block
    uint_8 driveAddrRegVal = 0b11100000 | ((lbaBlock >> 24) & 0x0F); 
    portByteOut(DRIVE_ADDR_REG, driveAddrRegVal);

    portByteOut(SECTOR_COUNT_REG, sectorCount);

    portByteOut(COMMAND_REG, READ_SECTORS_WITH_RETRY_CMD);

    waitingTask = getCurrentTask();
    blockTask();

    unlockScheduler();
}

void readSector() {
    for (int i = 0; i < 256; i++) {
        uint_16 data = portWordIn(DATA_REG);
        readBuffer[readBufferIndex + i] = data;
    }

    readBufferIndex += 256;
}

void driveISR(interrupt_frame *frame) {
    println("drive isr");

    uint_8 status = portByteIn(STATUS_REG);

    if (status & Status::BSY) return;

    if (status & Status::ERR || status & Status::DF) {
        print("Drive Error");
    }
    
    if (status & Status::DRQ && identify) {
        readSector();
        identify = false;
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
    portByteOut(DRIVE_REG, 0xE0);
    portByteOut(SECTOR_COUNT_REG, 0);
    portByteOut(LBA_LOW_REG, 0);
    portByteOut(LBA_MID_REG, 0);
    portByteOut(LBA_HIGH_REG, 0);

    identify = true;
    portByteOut(COMMAND_REG, IDENTIFY_CMD);
    
    uint_8 status = portByteIn(STATUS_REG);
    if (status == 0) {
        println("Drive doesn't exist.");
    }

    // 14 for primary ATA Hard Disk
    registerInterrupt(0x2E, driveISR, Gate::interrupt);
}