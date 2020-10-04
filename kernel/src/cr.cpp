#include <cr.h>

void setCR0(uint_32 value) {
    __asm__ volatile (
        "mov %%edx, %%cr0" : : "d" (value)
    );
}

void setCR2(uint_32 value) {
    __asm__ volatile (
        "mov %%edx, %%cr2" : : "d" (value)
    );
}

void setCR3(uint_32 value) {
    __asm__ volatile (
        "mov %%edx, %%cr3" : : "d" (value)
    );
}

void setCR4(uint_32 value) {
    __asm__ volatile (
        "mov %%edx, %%cr4" : : "d" (value)
    );
}

uint_32 getCR0() {
    uint_32 cr0;
    __asm__ (
        "mov %%cr0, %%eax" : "=a" (cr0)
    );
    
    return cr0;
}

uint_32 getCR2() {
    uint_32 cr2;
    __asm__ (
        "mov %%cr2, %%eax" : "=a" (cr2)
    );
    
    return cr2;
}

uint_32 getCR3() {
    uint_32 cr3;
    __asm__ (
        "mov %%cr3, %%eax" : "=a" (cr3)
    );
    
    return cr3;
}

uint_32 getCR4() {
    uint_32 cr4;
    __asm__ (
        "mov %%cr4, %%eax" : "=a" (cr4)
    );
    
    return cr4;
}