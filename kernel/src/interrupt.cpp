#include <interrupt.h>

void registerInterrupt(uint_8 interrupt, void *isr, Gate type, uint_8 dpl) {
    IDTEntry entry;

    uint_32 isrAddr = (uint_32)isr;
    entry.offset1 = isrAddr & 0x0000FFFF;
    entry.offset2 = (isrAddr & 0xFFFF0000) >> 16;
    entry.selector = 0x08;
    entry.zero = 0;
    entry.typeAttr = type;
    entry.typeAttr |= (0x80 + ((dpl & 0x3) << 5)); // P(1), DPL, S(0)

    setEntry(interrupt, entry);
} 