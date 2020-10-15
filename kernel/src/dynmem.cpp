#include <dynmem.h>
#include <virtmem.h>
#include <sync.h>
#include <memory.h>

#define MAX_PAGE_GROUPS 1024

typedef struct PageGroup {
    uint_32 ptr;
    size_t npages;
    size_t allocations;
} PageGroup;

static PageGroup pageGroups[MAX_PAGE_GROUPS];
static size_t pageGroupsCount;

static Mutex pageGroupsLock;

uint_32 getPagePtr(uint_32 ptr) {
    return (ptr / PAGE_SIZE) * PAGE_SIZE;
}

uint_32 getMemLeftInPage(uint_32 ptr) {
    return (PAGE_SIZE - (ptr % PAGE_SIZE));
}

void * kmalloc(size_t size) {
    pageGroupsLock.wait();
    if (pageGroupsCount == MAX_PAGE_GROUPS) {
        pageGroupsLock.release();
        return nullptr;
    }
        
    if (size < PAGE_SIZE) {
        for (size_t i = 0; i < pageGroupsCount; i++)
        {
            PageGroup *pageGroup = pageGroups + i;
            // This means there's no room in the last page of the page group
            if (pageGroup->ptr % PAGE_SIZE == 0) continue;

            if (size <= getMemLeftInPage(pageGroup->ptr)) {
                pageGroup->allocations++;
                uint_32 chosenPtr = pageGroup->ptr;
                pageGroup->ptr += size;
                
                pageGroupsLock.release();
                return (void*)chosenPtr;
            }
        }
    }

    uint_32 npages = (size / PAGE_SIZE) + (size % PAGE_SIZE != 0);

    uint_32 firstPage = kallocPage(npages);

    pageGroups[pageGroupsCount++] = {
        firstPage + size, 
        npages,
        1
    };
    
    pageGroupsLock.release();
    return (void*)firstPage;
}

void * kcalloc(size_t size) {
    void* ptr = kmalloc(size);
    if (ptr == nullptr) return ptr;

    return memset(ptr, 0, size);
}

void kfree(void *ptr) {
    auto ptrVal = (uint_32)ptr;

    pageGroupsLock.wait();
    for (size_t i = 0; i < pageGroupsCount; i++)
    {
        PageGroup *pageGroup = pageGroups + i;

        uint_32 pageGroupLastPage;
        // This means there's no room in the last page of the page group
        if (pageGroup->ptr % PAGE_SIZE == 0) pageGroupLastPage = pageGroup->ptr - PAGE_SIZE;
        else pageGroupLastPage = getPagePtr(pageGroup->ptr);
        
        bool inLastPage = (pageGroupLastPage <= ptrVal && ptrVal < pageGroupLastPage + PAGE_SIZE);
        uint_32 firstPageInGroup = (pageGroupLastPage - (pageGroup->npages - 1));
        bool isFirstPage = (ptrVal == firstPageInGroup);
        if (inLastPage || isFirstPage) {
            // Can optimize this in several, relatively easy ways.
            // Instead of immediately checking for 0 allocations, instead leave it be and increment a counter.
            // kmalloc can identify 0 allocations page groups and use them to allocate new data, maybe only for npages == 1.
            // even free all pages except for 1.
            // with/without kmalloc using these, we can only raise a counter for "empty page groups"
            // and free the pages only after a certain threshold is passed. 
            if (0 == --pageGroup->allocations) {
                kfreePages(firstPageInGroup, pageGroup->npages);
                pageGroups[i] = pageGroups[--pageGroupsCount];
            }

            break;
        }
    }
    
    pageGroupsLock.release();
}

void dynmemInit() {
    pageGroupsLock = Mutex();
}