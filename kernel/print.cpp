char* VIDEO_MEM = (char*)0xb8000;

void print(const char* s) {
    while (char c = *(s++) != '\0') {
        *(VIDEO_MEM++) = c;
    }
}