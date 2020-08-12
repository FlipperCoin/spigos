#include <port.h>
#include <screen.h>
#include <memory.h>
#include <format.h>

void printAt(char const*, int, int);
void printAt(char, int, int);
void printAt(unsigned char, int, int, unsigned char);
int getEndLine(int);
short getOffset(int, int);
void writeToVideoMem(unsigned short, unsigned int);
unsigned short getVgaCharacter(unsigned char, unsigned char);
short handleScrolling(short);

void println() {
    print('\n');
}

void println(char const* s) {
    print(s);
    print('\n');
}

void print(char const* s) {
    printAt(s, -1, -1);
}

void print(char c) {
    printAt(c, -1, -1);
}

void printHex(uint_32 value) {
    // length 11: 2 for "0x" + 8 for FFFFFFFF + 1 for null terminator
    char buf[10];
    itoh(value, buf, 10);
    print(buf);
}

void printNum(uint_32 value) {
    // 11 because max uint value 4294967295 (10 chars + null terminator)
    char buf[11];
    itoa(value, buf, 11);
    print(buf);
}

void printAt(char const* s, int col, int row) {
    if (col >=0 && row >= 0) {
        setCurser(getOffset(col, row));
    }
    
    while (char c = *(s++)) {
        printAt(c, -1, -1);
    }
}

void printAt(char c, int col, int row) {
    printAt(c, col, row, WHITE_ON_BLACK);
}

void printAt(unsigned char c, int col, int row, unsigned char attr) {
    short offset = 0;

    if (col >= 0 && row >= 0) {
        offset = getOffset(col, row);
    }
    else {
        offset = getCurser();
    }

    if (c == '\n') {
        offset = getEndLine(offset);
    } else if (c == '\t') {
        offset += 3;
    } else {
        writeToVideoMem(getVgaCharacter(c, attr), offset);
    }

    offset += 1;

    offset = handleScrolling(offset);

    setCurser(offset);
}

void backspace() {
    short offset = getCurser() - 1;

    writeToVideoMem(getVgaCharacter(' ', WHITE_ON_BLACK), offset);

    setCurser(offset);
}

void enter() {
    setCurser(getEndLine(getCurser()) + 1);
}

int getEndLine(int offset) {
    return (MAX_COLS * (offset / MAX_COLS + 1)) - 1;
}

short getOffset(int col, int row) {
    return  ((row * MAX_COLS) + col);
}

void writeToVideoMem(unsigned short c, unsigned int offset) {
    unsigned short *vidmem = (unsigned short*)VIDEO_ADDRESS;
    vidmem[offset] = c;
}

unsigned short getVgaCharacter(unsigned char c, unsigned char attr) {
    return (attr << 8) + c;
}

short getCurser() {
    portByteOut(REG_SCREEN_ADDR, H_CURSOR_OFF);
    unsigned char hCursorOffset = portByteIn(REG_SCREEN_DATA);
    portByteOut(REG_SCREEN_ADDR, L_CURSOR_OFF);
    unsigned char lCursorOffset = portByteIn(REG_SCREEN_DATA);

    return (hCursorOffset << 8) + lCursorOffset;
}

void setCurser(short offset) {
    portByteOut(REG_SCREEN_ADDR, H_CURSOR_OFF);
    portByteOut(REG_SCREEN_DATA, offset >> 8);
    portByteOut(REG_SCREEN_ADDR, L_CURSOR_OFF);
    portByteOut(REG_SCREEN_DATA, offset & 0xFF);
}

short handleScrolling(short offset) {
    if (offset > MAX_VID_OFFSET) {
        short* vidmem = (short*)VIDEO_ADDRESS;
        int rowsUp = (offset - MAX_VID_OFFSET) / MAX_COLS + 1;
        short vidmemcopy[MAX_VID_OFFSET + 1];
        memcpy(vidmemcopy, vidmem + rowsUp*MAX_COLS, sizeof(short)*(MAX_VID_OFFSET + 1));
        memcpy(vidmem, vidmemcopy, sizeof(short)*(MAX_VID_OFFSET + 1));
        offset = offset - rowsUp*MAX_COLS;
    }
    return offset;
}

void clearScreen() {
    short* vidmem = (short*)VIDEO_ADDRESS;
    for (int i = 0; i <= MAX_VID_OFFSET; i++) {
        vidmem[i] &= 0xFF00;
    }
    
    setCurser(0);
}