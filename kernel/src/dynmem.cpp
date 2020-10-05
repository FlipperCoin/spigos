#include <dynmem.h>
#include <virtmem.h>

#define MAX_ALLOCATIONS 1024

typedef struct AllocatedMemRecord {
    void *ptr;
    size_t npages;
} AllocatedMemRecord;

AllocatedMemRecord memoryAllocations[MAX_ALLOCATIONS];
size_t allocations = 0;

// TODO: mutex for multi task safety

void * kmalloc(size_t size) {
    if (allocations == MAX_ALLOCATIONS) return nullptr;

    size_t npages = size / PAGE_SIZE;
    if (size % PAGE_SIZE != 0) npages++;

    void *ptr = (void*)kallocPage(npages);
    memoryAllocations[allocations++] = {ptr,npages};
    return ptr;
}

void kfree(void *ptr) {
    for (size_t i = 0; i < allocations; i++)
    {
        AllocatedMemRecord *record = memoryAllocations + i;
        if(record->ptr == ptr) {
            kfreePages((uint_32)record->ptr, record->npages);

            memoryAllocations[i] = memoryAllocations[--allocations];

            return;
        }
    }
    
}