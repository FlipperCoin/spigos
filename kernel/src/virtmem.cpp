#include <virtmem.h>
#include <cr.h>
#include <physmem.h>
#include <screen.h>
#include <interrupt.h>
#include <memory.h>
#include <dynmem.h>

PageDirectory kPageDirectory __attribute__((aligned(4096)));

PageDirectory *getKernelPageDirectory() {
    return &kPageDirectory;
}

uint_32 createPageDirectoryEntry(uint_32 *pageTable, PageDirectoryEntryFlags flags) {
    return (uint_32)pageTable | (uint_32)flags;
}

uint_32 createPageTableEntry(void *pageFrameAddr, PageTableEntryFlags flags) {
    return (uint_32)pageFrameAddr | (uint_32)flags;
}

uint_32 * getPageTableFromPde(uint_32 *pde) {
    return (uint_32*)(*pde & 0xFFFFF000);
}

PageDirectoryEntryFlags getFlagsFromPde(uint_32 *pde) {
    return (PageDirectoryEntryFlags)(*pde & 0x000000FF);
}

uint_32 getPhysicalAddressFromPte(uint_32 *pte) {
    return *pte & 0xFFFFF000;
}

bool isPageAllocated(uint_32 *pte) {
    return (getPhysicalAddressFromPte(pte) == 0);
}

bool isPdeAllocated(uint_32 *pde) {
    return getPageTableFromPde(pde) != 0;
} 

uint_32 virtToPhys(PageDirectory *pageDirectory, uint_32 virtualAddress) {
    uint_32 *pageTable = getPageTableFromPde(&pageDirectory->Entries[(virtualAddress / PAGE_SIZE) / PAGE_TABLE_ENTRIES]);
    return getPhysicalAddressFromPte(&pageTable[(virtualAddress / PAGE_SIZE) % PAGE_TABLE_ENTRIES]);
}

void map(PageDirectory *pageDirectory, uint_32 virtualAddress, uint_32 physicalAddress, uint_32 npages, bool user) {
    if ((virtualAddress % PAGE_SIZE) != 0 || (physicalAddress % PAGE_SIZE) != 0) {
        // for now code below doesn't support addresses that are not page aligned
        return;
    }
    
    uint_32 page = virtualAddress / PAGE_SIZE;
    uint_32 pageFrame = physicalAddress / PAGE_SIZE;
    for (size_t i = 0; i < npages; i++) {
        uint_32 pdeIdx = (page + i) / PAGE_TABLE_ENTRIES;
        uint_32 pteIdx = (page + i) % PAGE_TABLE_ENTRIES;

        uint_32 *pde = &pageDirectory->Entries[pdeIdx];

        if (!isPdeAllocated(pde)) {
            pageDirectory->Entries[pdeIdx] = createPageDirectoryEntry(
                (uint_32*)kallocPageFrame(1), 
                (PageDirectoryEntryFlags)((uint_32)PageDirectoryEntryFlags::RW | (uint_32)PageDirectoryEntryFlags::Present)
            );
        }

        if (user && (((uint_32)getFlagsFromPde(pde) & (uint_32)PageDirectoryEntryFlags::User) == 0)) {
            *pde |= (uint_32)PageDirectoryEntryFlags::User;
        }

        uint_32 *pageTable = getPageTableFromPde(pde);

        pageTable[pteIdx] = createPageTableEntry(
            (void*)((pageFrame + i) * PAGE_SIZE),
            (PageTableEntryFlags)((uint_32)PageTableEntryFlags::RW | (uint_32)PageTableEntryFlags::Present | (user ? (uint_32)PageTableEntryFlags::User : 0))
        );
    }
}

void selfMap(PageDirectory *pd, uint_32 startAddr, uint_32 endAddr) {
    if (((endAddr - startAddr) % PAGE_SIZE) != 0) {
        // doesn't support address ranges that don't fit whole pages
        return;
    }

    uint_32 numberOfPages = (endAddr - startAddr) / PAGE_SIZE;
    
    map(pd, startAddr, startAddr, numberOfPages);
}

uint_32 kallocPagePhysical(size_t npages) {
    uint_32 physAddress = kallocPageFrame(npages);
    uint_32 virtAddress = physAddress;
    
    map(&kPageDirectory, virtAddress, physAddress, npages);
    
    return physAddress;
}

uint_32 kallocPage(size_t npages) {
    uint_32 physAddress = kallocPageFrame(npages);
    uint_32 virtAddress = physAddress;
    
    map(&kPageDirectory, virtAddress, physAddress, npages);
    
    return virtAddress;
}

void kfreePages(uint_32 virtualAddress, size_t npages) {
    uint_32 page = virtualAddress / PAGE_SIZE;
    for (size_t i = 0; i < npages; i++) {
        uint_32 pdeIdx = (page + i) / PAGE_TABLE_ENTRIES;
        uint_32 pteIdx = (page + i) % PAGE_TABLE_ENTRIES;

        uint_32 *pde = &kPageDirectory.Entries[pdeIdx];
        uint_32 *pageTable = getPageTableFromPde(pde);

        uint_32 physicalAddress = getPhysicalAddressFromPte(&pageTable[pteIdx]);

        if (i == 0) kfreePageFrames(physicalAddress, npages);

        pageTable[pteIdx] = createPageTableEntry(
            nullptr,
            (PageTableEntryFlags)0
        );
    }
}

void copyTable(uint_32 *ptd, uint_32 *pts) {
    memcpy(ptd, pts, PAGE_TABLE_ENTRIES * sizeof(uint_32));
}

void setKernelMappings(PageDirectory *pd) {
    PageDirectory *kpd = &kPageDirectory;

    for (size_t i = 0; i < PAGE_DIRECTORY_ENTRIES; i++)
    {
        if (!isPdeAllocated(&kpd->Entries[i])) {
            pd->Entries[i] = createPageDirectoryEntry(nullptr, PageDirectoryEntryFlags::RW);
            continue;
        }

        auto pt = (uint_32*)kallocPageFrame(1);
        uint_32* kpde = &kpd->Entries[i];
        uint_32* kpt = getPageTableFromPde(kpde);

        // if user can't access anything in the table, so kernel table
        if ((*kpde & (uint_32)PageDirectoryEntryFlags::User) == 0) {
            copyTable(pt, kpt);
            pd->Entries[i] = createPageDirectoryEntry(pt, getFlagsFromPde(kpde));
        }
        else {
            // look for kernel pages
            for (size_t j = 0; j < PAGE_TABLE_ENTRIES; j++)
            {
                if (isPageAllocated(&kpt[j]) && (*kpt & (uint_32)PageTableEntryFlags::User == 0)) {
                    pt[j] = kpt[j];
                }
            }
        }
    }
}

PageDirectory *createUserPageDirectory() {
    auto userPd = (PageDirectory*)kallocPagePhysical(1);

    setKernelMappings(userPd);

    return userPd;
}

void initTables() {
    PageDirectory *pd = &kPageDirectory;

    for (size_t i = 0; i < PAGE_DIRECTORY_ENTRIES; i++)
    {
        pd->Entries[i] = createPageDirectoryEntry(nullptr, PageDirectoryEntryFlags::RW);
    }

    uint_32 kernelStart = 0x00100000; // selfMap works because this addr is page aligned, otherwise need to improve selfMap impl
    uint_32 kernelEnd = 0x00F00000;

    uint_32 dynamicPhysMemStart = 0x01000000;
    uint_32 dynamicPhysMemEnd = 0x0C000000;

    selfMap(pd, kernelStart, kernelEnd);
    selfMap(pd, dynamicPhysMemStart, dynamicPhysMemEnd);
    // TODO: cleaner design with this
    // maybe provide a kernel "allocate" method for specific addresses and sizes so drivers like the display driver will be able to allocate this address
    // 0xb8000 - hardware mapped IO for VGA, 0xb87d0 (so up to 0xb9000 for page alignment) is the last addr I believe the screen driver will use
    // EDIT: actually 0xb9000 still failed, so move up to 0xba000 (so many hacks >_<)
    selfMap(pd, 0xb8000, 0xba000); 

    // IHAVENOIDEAWHY*SOB*:
    selfMap(pd, 0x0000, 0x1000); // on timeUpdate procedure, specifically the while statement "while (i < newSleepingTasksCount && j < sleepingTasksCount)"??? 
    selfMap(pd, 0x00001000, 0x00002000);
}

void initCr3() {
    setCR3((uint_32)&kPageDirectory);
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