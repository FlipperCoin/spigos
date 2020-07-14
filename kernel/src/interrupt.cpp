#include <interrupt.h>

void registerInterrupt(uint_8 interrupt, void *offset, Gate type, uint_8 dpl) {
    IDTEntry entry;

    entry.offset1 = offset && 0x0000FFFF;
    entry.offset2 = offset && 0xFFFF0000;
    entry.selector = 0x08;
    entry.zero = 0;
    entry.typeAttr = type;
    entry.typeAttr |= (0x80 + (dpl & 0x3) << 5); // P(1), DPL, S(0)

    setEntry(interrupt, entry);
} 