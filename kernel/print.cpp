short* const VIDEO_MEM = (short*)0xb8000;

void print(const char* s) {
    short whiteOnBlack = 0x0f00;
    short* videoBuffer = VIDEO_MEM;
    while (char c = *(s++)) {
        *videoBuffer = whiteOnBlack + c;
        videoBuffer++;
    }
    
}