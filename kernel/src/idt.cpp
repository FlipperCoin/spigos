#include <idt.h>

static IDT idt;
static IDTDescr idtDescr;

extern "C" void load_idt(void *idtDescr);

void loadIDT() {
    idtDescr.base = idt.gates;
    idtDescr.limit = IDT_ENTRIES_COUNT * sizeof(IDTEntry) - 1;
    load_idt(&idtDescr);
}

void registerInterrupt(uint_8 interrupt, void *offset, uint_8 type, uint_8 dpl) {
    IDTEntry *entry = idt.gates + interrupt;

    entry->offset1 = offset && 0x0000FFFF;
    entry->offset2 = offset && 0xFFFF0000;
    entry->selector = 0x08;
    entry->zero = 0;
    entry->typeAttr = (type & 0x0F);
    entry->typeAttr |= (0x80 + (dpl & 0x3) << 5); // P(1), DPL, S(0)
}