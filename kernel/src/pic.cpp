#include <types.h>
#include <pic.h>
#include <port.h>

void maskAll() {
    portByteOut(PIC1_DATA, 0xFF);
    portByteOut(PIC2_DATA, 0xFB);
}

int setIRQMask(uint_8 line) {
    uint_16 port;

    if (line < 8) {
        port = PIC1_DATA;
    } else if (line < 16) {
        port = PIC2_DATA;
        line -= 8;
    }
    else {
        return -1;
    }

    uint_8 maskBitmap = portByteIn(port);
    maskBitmap |= (1 << line); // line in bitmap
    portByteOut(port, maskBitmap);
    return 0;
}

int clearIRQMask(uint_8 line) {
    uint_16 port;

    if (line < 8) {
        port = PIC1_DATA;
    } else if (line < 16) {
        port = PIC2_DATA;
        line -= 8;
    }
    else {
        return -1;
    }

    uint_8 maskBitmap = portByteIn(port);
    maskBitmap &= ~(1 << line); // line in bitmap
    portByteOut(port, maskBitmap);
    return 0;
}

int remapPIC(uint_8 masterOffset, uint_8 slaveOffset) {
    if (masterOffset % 8 || slaveOffset % 8 || masterOffset == slaveOffset) {
        return -1;
    }

    uint_8 masterMask = portByteIn(PIC1_DATA);
    uint_8 slaveMask = portByteIn(PIC2_DATA);
    
    portByteOut(PIC1_COMMAND, ICW1 | ICW1Flags::ICW4Present);
    portByteOut(PIC2_COMMAND, ICW1 | ICW1Flags::ICW4Present);

    portByteOut(PIC1_DATA, masterOffset);
    portByteOut(PIC1_DATA, 0x04); // A slave is only connected at pin 3
    portByteOut(PIC1_DATA, ICW4);
    
    portByteOut(PIC2_DATA, slaveOffset);
    portByteOut(PIC2_DATA, 2); // connected to IRQ2
    portByteOut(PIC2_DATA, ICW4);

    portByteOut(PIC1_DATA, masterMask);
    portByteOut(PIC2_DATA, slaveMask);

    return 0;
}

void sendEOI(bool isSlave) {
    uint_8 eoi = OCW2 | OCW2Flags::EOI;
    
    portByteOut(PIC1_COMMAND, eoi);
    if (isSlave) {
        portByteOut(PIC2_COMMAND, eoi);
    }
}

uint_16 getRegister(uint_8 reg) {
    portByteOut(PIC1_COMMAND, OCW3 | 0x02 | reg); 
    portByteOut(PIC2_COMMAND, OCW3 | 0x02 | reg); 

    return (portByteIn(PIC2_COMMAND) << 8) | portByteIn(PIC1_COMMAND);
}

uint_16 getIRR() {
    return getRegister(0);
}

uint_16 getISR() {
    return getRegister(1);
}

int initPIC() {
    maskAll();
    int err;
    if (err = remapPIC(0x20, 0x28)) return err;
    
    return 0;
}

void enableHardwareInterrupts() {
    clearIRQMask(0x0E); // primary ATA 
    clearIRQMask(0x02); // cascade from slave to master PIC
    clearIRQMask(0x01); // keyboard
    clearIRQMask(0x00); // timer
}