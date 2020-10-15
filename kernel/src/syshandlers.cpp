#include <syshandlers.h>
#include <syscall.h>
#include <types.h>
#include <screen.h>
#include <memory.h>
#include <dynmem.h>
#include <pit.h>

// TODO: change to write with fd
int write(void *buf, size_t num) {
    char bcpy[num+1];
    memcpy(bcpy, buf, num);
    bcpy[num] = '\0';
    print(bcpy);
    return num;
}

int millisleep(uint_32 ms) {
    sleep(ms);
    return 1;
}

void initSyscallHandlers() {
    registerSyscallHandler(4, (int (*)(uint_32,uint_32,uint_32,uint_32,uint_32))write);
    registerSyscallHandler(162, (int (*)(uint_32,uint_32,uint_32,uint_32,uint_32))millisleep);
}