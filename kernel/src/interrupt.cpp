#include <interrupt.h>
#include <screen.h>

// extern void (*isrWrappers[IDT_ENTRIES_COUNT])(interrupt_frame*);
extern void (*isrWrappers[49])(interrupt_frame*);

// void (*registeredIsrs[IDT_ENTRIES_COUNT])(interrupt_frame*);
void (*registeredIsrs[49])(interrupt_frame*);

void registerInterrupt(uint_8 interrupt, void (*isr)(interrupt_frame*), Gate type, uint_8 dpl) {
    registeredIsrs[interrupt] = isr;

    IDTEntry entry;

    uint_32 isrAddr = (uint_32)isrWrappers[interrupt];
    
    entry.offset1 = isrAddr & 0x0000FFFF;
    entry.offset2 = (isrAddr & 0xFFFF0000) >> 16;
    entry.selector = 0x08;
    entry.zero = 0;
    entry.typeAttr = type;
    entry.typeAttr |= (0x80 + ((dpl & 0x3) << 5)); // P(1), DPL, S(0)

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