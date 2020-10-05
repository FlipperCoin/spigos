#include <types.h>

#define PAGE_FRAME_SIZE 0x1000

enum class PageFrameStatus {
    Free = 0,
    Used = 1
};

void initPhysMemManagement();
uint_32 kallocPageFrame(size_t numOfPages);
void kfreePageFrames(uint_32 pageFrameAddr, size_t numOfPages);