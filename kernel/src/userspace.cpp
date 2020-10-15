#include <userspace.h>
#include <syscall.h>
#include <syshandlers.h>

void initUserspace() {
    initSyscalls();
    initSyscallHandlers();
}