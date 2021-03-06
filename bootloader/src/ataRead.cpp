// Registers

#define DATA_REG 0x1F0 
#define ERROR_REG 0x1F1
#define FEATURES_REG 0x1F1
#define SECTOR_COUNT_REG 0x1F2
#define LBA_LOW_REG 0x1F3
#define LBA_MID_REG 0x1F4
#define LBA_HIGH_REG 0x1F5
#define DRIVE_REG 0x1F6
#define STATUS_REG 0x1F7
#define COMMAND_REG 0x1F7

#define ALT_STATUS_REG 0x3F6
#define DEV_CONTROL_REG 0x3F6
#define DRIVE_ADDR_REG 0x3F7

// Commands

#define READ_SECTORS_WITH_RETRY_CMD 0x20
#define READ_SECTORS_WITHOUT_RETRY_CMD 0x21
#define WRITE_SECTORS_WITH_RETRY_CMD 0x30
#define WRITE_SECTORS_WITHOUT_RETRY_CMD 0x31
#define IDENTIFY_CMD 0xEC

// Register Values

enum Error {
    AMNF = 0, // Address mark not found.
    TKZNF = 1, // Track zero not found.
    ABRT = 2, // Aborted command.
    MCR = 3, // Media change request.
    IDNF = 4, // ID not found.
    MC = 5, // Media changed.
    UNC = 6, // Uncorrectable data error.
    BBK = 7, // Bad Block detected.
};

enum Status {
    ERR = 0x01, // Indicates an error occurred. Send a new command to clear it (or nuke it with a Software Reset).
    IDX = 0x02, // Index. Always set to zero.
    CORR = 0x04, // Corrected data. Always set to zero.
    DRQ = 0x08, // Set when the drive has PIO data to transfer, or is ready to accept PIO data.
    SRV = 0x10, // Overlapped Mode Service Request.
    DF = 0x20, // Drive Fault Error (does not set ERR).
    RDY = 0x40, // Bit is clear when drive is spun down, or after an error. Set otherwise.
    BSY = 0x80 // Indicates the drive is preparing to send/receive data (wait for it to clear). In case of 'hang' (it never clears), do a software reset.
};

void print(char *msg);

unsigned char portByteIn(unsigned short port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void portByteOut(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : :"a" (data), "d" (port));
}

unsigned short portWordIn(unsigned short port) {
    unsigned short result;
    asm ("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

void waitBSY() {
    while (portByteIn(ALT_STATUS_REG) & Status::BSY);
}

void waitDRQ() {
    while (!(portByteIn(ALT_STATUS_REG) & Status::DRQ));
}

void ataRead(unsigned int lbaBlock, unsigned char sectorCount, unsigned char *buffer) {
    waitBSY();

    // always set (1), LBA Addressing (1), always set (1), master drive number (0), bits 24-27 of LBA block
    unsigned char driveAddrRegVal = 0b11100000 | ((lbaBlock >> 24) & 0x0F); 
    portByteOut(DRIVE_REG, driveAddrRegVal);

    portByteOut(FEATURES_REG, 0x00);

    portByteOut(LBA_LOW_REG, lbaBlock & 0xFF);
    portByteOut(LBA_MID_REG, ((lbaBlock >> 8) & 0xFF));
    portByteOut(LBA_HIGH_REG, ((lbaBlock >> 16)) & 0xFF);
    portByteOut(SECTOR_COUNT_REG, sectorCount);

    portByteOut(COMMAND_REG, READ_SECTORS_WITH_RETRY_CMD);

    auto sectorsBuffer = (unsigned short *)buffer;
    while (0 != sectorCount--) {
        waitBSY();
        waitDRQ();

        for (int i = 0; i < 256; i++) {
            sectorsBuffer[i] = portWordIn(DATA_REG);
        }

        sectorsBuffer += 256;
    }    
}