#include <types.h>
#include <port.h>

uint_8 portByteIn(uint_16 port) {
    uint_8 result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void portByteOut(uint_16 port, uint_8 data) {
    __asm__("out %%al, %%dx" : :"a" (data), "d" (port));
}

uint_16 portWordIn(uint_16 port) {
    uint_16 result;
    asm ("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

void portWordOut(uint_16 port, uint_16 data) {
    __asm__("out %%ax, %%dx" : :"a" (data), "d" (port));
}