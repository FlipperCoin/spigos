#include <disk.h>
#include <ata.h>
#include <memory.h>

void readBuffer(size_t start, uint_8 *buf, size_t size) {
    size_t sector = start / 512;
    size_t off = start % 512;
    
    size_t nsectors = ((off + size) / 512) + (((off + size) % 512) != 0);

    uint_8 sectBuf[nsectors * 512];
    read(sector,nsectors,sectBuf);

    memcpy(buf, sectBuf + off, size);
}