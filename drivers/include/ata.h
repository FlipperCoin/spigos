#include <types.h>

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

#define READ_SECTORS_WITH_RETRY_CMD 20
#define WRITE_SECTORS_WITH_RETRY_CMD 30
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
    ERR = 0, // Indicates an error occurred. Send a new command to clear it (or nuke it with a Software Reset).
    IDX = 1, // Index. Always set to zero.
    CORR = 2, // Corrected data. Always set to zero.
    DRQ = 3, // Set when the drive has PIO data to transfer, or is ready to accept PIO data.
    SRV = 4, // Overlapped Mode Service Request.
    DF = 5, // Drive Fault Error (does not set ERR).
    RDY = 6, // Bit is clear when drive is spun down, or after an error. Set otherwise.
    BSY = 7 // Indicates the drive is preparing to send/receive data (wait for it to clear). In case of 'hang' (it never clears), do a software reset.
};

void initAta();
void read(uint_32 lbaBlock, uint_8 sectorCount, uint_8 *buffer);