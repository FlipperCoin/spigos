short* const VIDEO_MEM = (short*)0xb8000;

void print(const char* s) {
    short whiteOnBlack = 0x0f00;
    short* videoBuffer = VIDEO_MEM;
    for (; *s != '\0'; s++) {
        short c = whiteOnBlack + (*s);
        *videoBuffer = c;
        videoBuffer++;
    }
    // while (char c = *(s++) != '\0') {
    //     *(videoBuffer++) = c;
    // }
}