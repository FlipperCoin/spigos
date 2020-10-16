#include <filesystem.h>
#include <disk.h>
#include <dynmem.h>

File files[64];

File *getFile(size_t idx) {
    return &files[idx];
}

void loadFiles() {
    size_t addr = 512000;
    size_t i = 0;
    while (true) {
        uint_32 size;
        readBuffer(addr, (uint_8*)&size, sizeof(uint_32));
        addr += 4;

        if (size == 0) break;

        void *progBuf = kcalloc(size);
        readBuffer(addr, (uint_8*)progBuf, size);
        addr += size;

        files[i++] = {size, progBuf};
    }
}