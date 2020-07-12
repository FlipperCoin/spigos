#include <memory.h>

void * memcpy(void * destination, void const * source, unsigned int num ) {
    for (unsigned int i = 0; i < num; i++)
    {
        ((char*)destination)[i] = ((char*)source)[i];
    }
    return destination;
}