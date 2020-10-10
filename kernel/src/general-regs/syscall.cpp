#include <interrupt.h>
#include <screen.h>
#include <syscall.h>

//TODO: asm volatile read eax,ebx,ecx,edx (the compiler should preserve the registers)
__attribute__((interrupt))
void
syscall(interrupt_frame *frame){println("syscall");while(true){}}

void registerSyscall() {
    registerRawInterrupt(0x80, syscall, Gate::interrupt, USER_RING);
}