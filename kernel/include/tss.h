#include <types.h>

// A struct describing a Task State Segment.
typedef struct TssEntry
{
   uint_32 prev_tss;   // The previous TSS - if we used hardware task switching this would form a linked list.
   uint_32 esp0;       // The stack pointer to load when we change to kernel mode.
   uint_32 ss0;        // The stack segment to load when we change to kernel mode.
   uint_32 esp1;       // Unused...
   uint_32 ss1;
   uint_32 esp2;
   uint_32 ss2;
   uint_32 cr3;
   uint_32 eip;
   uint_32 eflags;
   uint_32 eax;
   uint_32 ecx;
   uint_32 edx;
   uint_32 ebx;
   uint_32 esp;
   uint_32 ebp;
   uint_32 esi;
   uint_32 edi;
   uint_32 es;         // The values to load into ES,CS,SS etc. when we change to kernel mode.
   uint_32 cs;         
   uint_32 ss;         
   uint_32 ds;         
   uint_32 fs;         
   uint_32 gs;         
   uint_32 ldt;        // Unused...
   uint_16 trap;
   uint_16 iomap_base;
} __attribute__((packed)) TssEntry;

void flushTSS(uint_32 tssDescIndex);