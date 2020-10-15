#include <types.h>

int registerSyscallHandler(uint_32 eax, int (*handler)(uint_32 ebx, uint_32 ecx, uint_32 edx, uint_32 esi, uint_32 edi));
void initSyscalls();