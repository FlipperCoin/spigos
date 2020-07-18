#include <memory.h>

void * memcpy(void * destination, void const * source, size_t num) {
    for (size_t i = 0; i < num; i++)
    {
        ((char*)destination)[i] = ((char*)source)[i];
    }
    return destination;
}

int memcmp (const void * ptr1, const void * ptr2, size_t num) {
    for (size_t i = 0; i < num; i++)
    {
        char diff = ((char*)ptr1)[i] - ((char*)ptr2)[i];
        if (diff != 0) return diff;
    }
    
    return 0;
}