#include <virtmem.h>
#include <cr.h>
#include <physmem.h>
#include <screen.h>
#include <interrupt.h>

#define PAGE_DIRECTORY_ENTRIES 1024
#define PAGE_TABLE_ENTRIES 1024

uint_32 pageDirectory[PAGE_DIRECTORY_ENTRIES] __attribute__((aligned(4096)));

uint_32 createPageDirectoryEntry(uint_32 *pageTable, PageDirectoryEntryFlags flags) {
    return (uint_32)pageTable | (uint_32)flags;
}

uint_32 createPageTableEntry(void *pageFrameAddr, PageTableEntryFlags flags) {
    return (uint_32)pageFrameAddr | (uint_32)flags;
}

uint_32 * getPageTableFromPde(uint_32 pde) {
    return (uint_32*)(pde & 0xFFFFF000);
}

bool isPdeAllocated(uint_32 pde) {
    return getPageTableFromPde(pde) != 0;
} 

bool isPteAllocated(uint_32 pte) {

}

uint_32 getPhysicalPageFrameAddressFromPTE(uint_32 pte) {
    
}

uint_32 getPhysicalAddress(uint_32 virtualAddr) {
    return -1; // didn't finish implementation yet

    uint_32 pageAlignedAddr = virtualAddr / 0x1000; // div by 0x1000 (=4096 decimal) because every page is 4 KiB
    uint_32 idxInPage = virtualAddr % 0x1000;
    
    uint_32 pdeIdx = pageAlignedAddr / 0x400; // div by 0x400 (=1024) for page directory idx because every page table covers 0x400 pages 
    uint_32 pteIdx = pageAlignedAddr % 0x400; // remainder for page table idx 

    uint_32 pde = pageDirectory[pdeIdx];
    if (!isPdeAllocated(pde)) {

    }

    uint_32 pte = getPageTableFromPde(pde)[pteIdx];
    if (!isPteAllocated(pte)) {

    }

    return getPhysicalPageFrameAddressFromPTE(pte) + idxInPage;
}

void selfMap(uint_32 startAddr, uint_32 endAddr) {
    if ((startAddr % PAGE_SIZE) != 0 || ((endAddr - startAddr) % PAGE_SIZE) != 0) {
        // for now code below doesn't support addresses that are not page aligned
        return;
    }

    uint_32 firstPage = startAddr / PAGE_SIZE;
    uint_32 numberOfPages = (endAddr - startAddr) / PAGE_SIZE;

    for (size_t page = firstPage; page < firstPage + numberOfPages; page++)
    {
        uint_32 pdeIdx = page / PAGE_TABLE_ENTRIES;
        uint_32 pteIdx = page % PAGE_TABLE_ENTRIES;

        if (!isPdeAllocated(pageDirectory[pdeIdx])) {
            pageDirectory[pdeIdx] = createPageDirectoryEntry(
                (uint_32*)kallocPageFrame(1), 
                (PageDirectoryEntryFlags)((uint_32)PageDirectoryEntryFlags::RW | (uint_32)PageDirectoryEntryFlags::Present)
            );
        }
        
        getPageTableFromPde(pageDirectory[pdeIdx])[pteIdx] = createPageTableEntry(
            (void *)(page * PAGE_SIZE), 
            (PageTableEntryFlags)((uint_32)PageTableEntryFlags::RW | (uint_32)PageTableEntryFlags::Present)
        );
    }
}

void initTables() {
    for (size_t i = 0; i < PAGE_DIRECTORY_ENTRIES; i++)
    {
        pageDirectory[i] = createPageDirectoryEntry(nullptr, PageDirectoryEntryFlags::RW);
    }

    uint_32 kernelStart = 0x00100000; // code below works because this addr is page aligned
    uint_32 kernelEnd = 0x00F00000;

    selfMap(kernelStart, kernelEnd);
    // TODO: cleaner design with this
    // maybe provide a kernel "allocate" method for specific addresses and sizes so drivers like the display driver will be able to allocate this address
    // 0xb8000 - hardware mapped IO for VGA, 0xb87d0 (so up to 0xb9000 for page alignment) is the last addr I believe the screen driver will use
    selfMap(0xb8000, 0xb9000); 

    // IHAVENOIDEAWHY*SOB*:
    selfMap(0x141b000,0x141b900); // idt EDIT: it was changed to 141b000 from 141a000, interesting its a page jump
    selfMap(0x00001000, 0x00002000);
    selfMap(0x00007000, 0x00008000);
    selfMap(0x0111b000, 0x0111c000); // runningTaskIndex var (with 40 in the end, not page aligned)
    selfMap(0x0111d000, 0x0111e000); // totalTicks PIT var (with 70 in the end, not page aligned), also registered isrs (with 80 in the end)
    selfMap(0x01410000, 0x01420000);
}

void initCr3() {
    setCR3((uint_32)pageDirectory);
}

void enablePaging() {
    uint_32 cr0 = getCR0();
    setCR0(cr0 | CR0Flags::PG);
}

void enableVirtualMemory() {
    initTables();

    initCr3();

    enablePaging();
}