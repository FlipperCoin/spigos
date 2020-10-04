#include <physmem.h>
#include <types.h>

// should be 0x100 aligned, if not need to calc the first 0x100 aligned address after this address because of page table entry structure
static const uint_32 pageFramesStartAddr = 0x01000000; 
static const uint_32 pageFramesNum = 0xBF000; // ((0x0C000000 - 0x01000000) / 0x1000)

PageFrameStatus pageFrameMap[pageFramesNum];

void initPhysMemManagement() {
    for (size_t i = 0; i < pageFramesNum; i++)
    {
        pageFrameMap[i] = PageFrameStatus::Free;
    }
}

uint_32 kallocPageFrame(size_t numOfPages) {
    uint_32 pagesLeft = numOfPages;

    uint_32 firstPageFound;
    for (size_t i = 0; i < pageFramesNum; i++)
    {
        if (pageFrameMap[i] == PageFrameStatus::Free) {
            if (pagesLeft == numOfPages) {
                firstPageFound = i;
            }
            pagesLeft--;
            if (pagesLeft == 0) {
                for (size_t j = firstPageFound; j < firstPageFound + numOfPages; j++)
                {
                    pageFrameMap[j] = PageFrameStatus::Used;
                }
                
                return (pageFramesStartAddr + (firstPageFound * PAGE_SIZE));
            }
        }
        else if (pageFrameMap[i] == PageFrameStatus::Used) {
            pagesLeft = numOfPages;
        }   
    }

    return -1;
}

void kfreePageFrames(uint_32 pageFrameAddr, size_t numOfPages) {
    size_t firstPage = (pageFrameAddr - pageFramesStartAddr) / PAGE_SIZE;
    
    for (size_t i = firstPage; i < firstPage + numOfPages; i++)
    {
        pageFrameMap[i] = PageFrameStatus::Free;
    }
}