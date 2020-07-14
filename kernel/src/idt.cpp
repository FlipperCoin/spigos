#include <idt.h>

static IDT idt;
static IDTDescr idtDescr;

extern "C" void load_idt(void *idtDescr);

void loadIDT() {
    idtDescr.base = idt.entries;
    idtDescr.limit = IDT_ENTRIES_COUNT * sizeof(IDTEntry) - 1;
    load_idt(&idtDescr);
}

void setEntry(uint_8 offset, IDTEntry entry) {
    idt.entries[offset] = entry;
}