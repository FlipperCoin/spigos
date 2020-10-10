#include <gdt.h>
#include <types.h>
#include <interrupt.h>
#include <screen.h>
#include <tss.h>

typedef union AccessFlags
{
    uint_8 Value;
    struct AccessFlagsBitField {
        uint_8 Accessed : 1;
        uint_8 ReadWrite : 1;
        uint_8 DirectionConforming : 1;
        uint_8 Executable : 1;
        uint_8 DescriptorType : 1; // S Bit
        uint_8 Priviledge : 2;
        uint_8 Present : 1;
    } Specific;
} AccessFlags;

typedef union DescriptorFlags2
{
    uint_8 Value;
    struct DescriptorFlagsBitField {
        uint_8 Empty : 6;
    } Specific;
} DescriptorFlags2;

typedef struct GlobalDescriptor {
    uint_16 LimitLow16;
    uint_32 BaseLow24 : 24;
    AccessFlags Flags;
    uint_8 LimitHigh4 : 4;
    uint_8 Empty : 2;
    uint_8 Granularity : 1;
    uint_8 Size : 1;
    uint_8 BaseHigh8;
} __attribute__((packed)) GlobalDescriptor;

typedef struct GDTDescriptor {
    uint_16 Size;
    uint_32 Offset;
} __attribute__((packed)) GDTDescriptor;

// 6 GDT ENTRIES: null entry, kernel code + data, user code + data, TSS
#define GDT_ENTRIES 6

GlobalDescriptor gdt[GDT_ENTRIES];
GDTDescriptor gdtDesc;

// gr: limit in 1B (false) or 4KiB blocks (true), size: 16 bit (false) or 32 bit (true) protected mode 
void setDescriptor(uint_32 segment, uint_32 base, uint_32 limit, uint_8 flags, bool gr = true, bool size = true) {
    GlobalDescriptor *gd = gdt + segment;

    gd->BaseLow24 = base & (0x00FFFFFF);
    gd->BaseHigh8 = base >> 24;
    gd->LimitLow16 = limit & 0xFFFF;
    gd->LimitHigh4 = (limit >> 16) & 0xF;
    gd->Flags.Value = flags;
    gd->Granularity = gr;
    gd->Size = size;
}

TssEntry kernelTss;

void setStateSegment(uint_32 segment, TssEntry *tss) {
    uint_32 base = (uint_32)tss;
    uint_32 limit = base + sizeof(TssEntry);

    setDescriptor(segment, base, limit, 0xE9, false, false);
}

void initKernelTss() {
    // honestly not sure whats the difference between ss0 & ss (or esp0 & esp...)
    kernelTss.ss0 = DATA_SEGMENT_KERNEL * sizeof(GlobalDescriptor); 
    kernelTss.esp0 = 0xEF0000;

    // added 3 is RPL (requested priv level) which is in the last 2 bits of the descriptor index
    // user level cause practically user is switching to kernel using this TSS
    kernelTss.cs = CODE_SEGMENT_KERNEL * sizeof(GlobalDescriptor) + 3;
    kernelTss.ss = kernelTss.ds = kernelTss.es = kernelTss.gs = kernelTss.fs = DATA_SEGMENT_KERNEL * sizeof(GlobalDescriptor) + 3;
}

extern "C" void gdt_flush(GDTDescriptor *gdtPtr);

void flushGDT(GDTDescriptor *gdtPtr) {
    gdt_flush(gdtPtr);
}

void initGdt() {
    setDescriptor(0, 0, 0, 0);
    setDescriptor(CODE_SEGMENT_KERNEL, 0, 0xFFFFF, 0x9A); //10011010b
    setDescriptor(DATA_SEGMENT_KERNEL, 0, 0xFFFFF, 0x92); //10010010b
    setDescriptor(CODE_SEGMENT_USER, 0, 0xFFFFF, 0xFA); //11111010b
    setDescriptor(DATA_SEGMENT_USER, 0, 0xFFFFF, 0xF2); //11110010b

    initKernelTss();
    uint_32 tssBase = (uint_32)&kernelTss;
    setDescriptor(KERNEL_TASK_STATE_SEGMENT, tssBase, tssBase + sizeof(TssEntry), 0xE9, false);

    gdtDesc = {GDT_ENTRIES * sizeof(GlobalDescriptor) - 1, (uint_32)gdt};

    flushGDT(&gdtDesc);
    flushTSS(KERNEL_TASK_STATE_SEGMENT * sizeof(GlobalDescriptor));
}