#include <interrupt.h>
#include <screen.h>
#include <syscall.h>
#include <registers.h>

#define SYSCALL_HANDLERS_MAX 255

static int (*handlers[SYSCALL_HANDLERS_MAX])(uint_32 ebx, uint_32 ecx, uint_32 edx, uint_32 esi, uint_32 edi);

extern "C" void syscall_wrap(InterruptFrame *frame);

extern "C" int syscall(InterruptFrame *frame, GeneralPurposeRegisters *regs) {
    uint_32 handlerNo = regs->eax;
    if (handlerNo >= SYSCALL_HANDLERS_MAX || handlers[handlerNo] == nullptr) {
        return -1;
    }

    return handlers[handlerNo](regs->ebx, regs->ecx, regs->edx, regs->esi, regs->edi);
}

int registerSyscallHandler(uint_32 eax, int (*handler)(uint_32 ebx, uint_32 ecx, uint_32 edx, uint_32 esi, uint_32 edi)) {
    if (eax >= SYSCALL_HANDLERS_MAX) {
        return -1;
    }

    handlers[eax] = handler;
}

void initSyscalls() {
    registerRawInterrupt(0x80, syscall_wrap, Gate::interrupt, USER_RING);
}