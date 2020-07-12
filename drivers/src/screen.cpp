#include <port.h>
#include <screen.h>
#include <memory.h>

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
        offset >>= 8;
    }

    if (c == '\n') {
        offset = getEndLine(offset);
    } else {
        writeToVideoMem(getVgaCharacter(c, attr), offset);
    }

    offset += 1;

    offset = handleScrolling(offset);

    setCurser(offset);
}

int getEndLine(int offset) {
    return (MAX_COLS * (offset / MAX_COLS + 1)) - 1;
}

short getOffset(int col, int row) {
    return  ((row * MAX_COLS) + col);
}

void writeToVideoMem(unsigned short c, unsigned int offset) {
    unsigned short *vidmem = (unsigned short*)0xb8000;
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
        memcpy(vidmemcopy, vidmem + rowsUp*MAX_COLS, MAX_VID_OFFSET + 1);
        offset = offset - rowsUp*MAX_COLS;
    }
    return offset;
}