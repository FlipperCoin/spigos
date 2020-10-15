#include <types.h>

void * kmalloc(size_t size);
void * kcalloc(size_t size);
void kfree(void *ptr);
void dynmemInit();