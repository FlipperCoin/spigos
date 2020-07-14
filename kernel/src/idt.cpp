#include <idt.h>
#include <screen.h>
#include <format.h>

static IDTEntry idt[IDT_ENTRIES_COUNT];
static IDTDescr idtDescr;

extern "C" void load_idt(void *idtDescr);

void loadIDT() {
    idtDescr.base = idt;
    idtDescr.limit = IDT_ENTRIES_COUNT * sizeof(IDTEntry) - 1;
    load_idt(&idtDescr);
}

void setEntry(uint_8 offset, IDTEntry entry) {
    idt[offset] = entry;
}