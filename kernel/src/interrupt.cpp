#include <interrupt.h>
#include <screen.h>

extern void (*isrWrappers[IDT_ENTRIES_COUNT])(interrupt_frame*);

void (*registeredIsrs[IDT_ENTRIES_COUNT])(interrupt_frame*);

void registerInterrupt(uint_8 interrupt, void (*isr)(interrupt_frame*), Gate type, uint_8 dpl) {
    registeredIsrs[interrupt] = isr;

    IDTEntry entry;

    registerRawInterrupt(interrupt, isrWrappers[interrupt], type, dpl);
} 

void registerRawInterrupt(uint_8 interrupt, void (*isr)(interrupt_frame*), Gate type, uint_8 dpl) {
    IDTEntry entry;
    uint_32 isrAddr = (uint_32)isr;

    entry.offset1 = isrAddr & 0x0000FFFF;
    entry.offset2 = (isrAddr & 0xFFFF0000) >> 16;
    entry.selector = 0x08;
    entry.zero = 0;
    entry.typeAttr = type;
    entry.typeAttr |= (0x80 + ((dpl & 0x3) << 5)); // P(1, set to 0 for unused interrupts), DPL (priviledge level), S(0, always 0 for interrupt and trap gates)

    setEntry(interrupt, entry);
}

uint_32 disableInterruptsCounter = 0;

void enableInterrupts() {
    if (disableInterrupts > 0)
        disableInterruptsCounter--;
    
    if (disableInterruptsCounter == 0) {
        __asm__ (
            "sti"
        );
    }
}

void disableInterrupts() {
    __asm__ (
        "cli"
    );
    disableInterruptsCounter++;
}