#include <types.h>

#define PAGE_SIZE 0x1000

enum class PageFrameStatus {
    Free = 0,
    Used = 1
};

void initPhysMemManagement();
uint_32 kallocPageFrame(size_t numOfPages);