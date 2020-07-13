#include <types.h>

#define IDT_ENTRIES_COUNT 256

typedef struct IDTEntry {
    uint_16 offset1;
    uint_16 selector;
    uint_8 zero;
    uint_8 typeAttr;
    uint_16 offset2;
} IDTEntry;

typedef struct IDTDescr {
    uint_16 limit;
    IDTEntry *base;
} IDTDescr;

typedef struct IDT {
    IDTEntry gates[IDT_ENTRIES_COUNT];
} IDT;

void loadIDT();
void registerInterrupt(uint_8 interrupt, void *offset, uint_8 type, uint_8 dpl);