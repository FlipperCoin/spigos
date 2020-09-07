#define VIDEO_MEM 0xb8000
#define WHITE_ON_BLACK 0x0f

void print(char *msg) {
    auto videoMemory = (unsigned short *)VIDEO_MEM;
    while (char c = *(msg++)) {
        *(videoMemory++) = WHITE_ON_BLACK << 8 | c;
    }
}