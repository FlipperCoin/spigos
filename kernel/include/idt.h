#pragma once

#include <types.h>

#define IDT_ENTRIES_COUNT 256

enum Gate {
    task = 0x05,
    interrupt = 0x0E,
    trap = 0x0F
};

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
} __attribute__((packed)) IDTDescr ;

void loadIDT();
void setEntry(uint_8 offset, IDTEntry entry);