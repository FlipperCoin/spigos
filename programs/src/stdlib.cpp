#include <stdlib.h>

int write(void *buf, size_t num) {
    int res;
    asm volatile ("\
        mov %2, %%ecx;\
        mov %1, %%ebx;\
        mov $4, %%eax;\
        int $0x80; \
        mov %%eax, %0; \
    " : "=r"(res): "r"(buf), "r"(num));
    return res;
}

int sleep(uint_32 ms) {
    int res;
    asm volatile ("\
        mov %1, %%ebx;\
        mov $162, %%eax;\
        int $0x80; \
        mov %%eax, %0; \
    " : "=r"(res): "r"(ms));
    return res;
}