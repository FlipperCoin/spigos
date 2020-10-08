#include <dynmem.h>
#include <virtmem.h>
#include <sync.h>

#define MAX_ALLOCATIONS 1024

typedef struct AllocatedMemRecord {
    void *ptr;
    size_t npages;
} AllocatedMemRecord;

static AllocatedMemRecord memoryAllocations[MAX_ALLOCATIONS];
static size_t allocations = 0;

static Mutex recordLock;

// TODO: mutex for multi task safety

void * kmalloc(size_t size) {
    recordLock.wait();
    if (allocations == MAX_ALLOCATIONS) {
        recordLock.release();
        return nullptr;
    }

    size_t npages = size / PAGE_SIZE;
    if (size % PAGE_SIZE != 0) npages++;

    void *ptr = (void*)kallocPage(npages);
    memoryAllocations[allocations++] = {ptr,npages};
    recordLock.release();
    return ptr;
}

void kfree(void *ptr) {
    recordLock.wait();
    for (size_t i = 0; i < allocations; i++)
    {
        AllocatedMemRecord *record = memoryAllocations + i;
        if(record->ptr == ptr) {
            kfreePages((uint_32)record->ptr, record->npages);

            memoryAllocations[i] = memoryAllocations[--allocations];
            break;
        }
    }

    recordLock.release();
}

void dynmemInit() {
    recordLock = Mutex();
}