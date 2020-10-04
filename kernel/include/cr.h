#include <types.h>

enum CR0Flags {
    PE = 0x01, // Protected Mode Enable	If 1, system is in protected mode, else system is in real mode
    MP = 0x02, // Monitor co-processor	Controls interaction of WAIT/FWAIT instructions with TS flag in CR0
    EM = 0x04, // Emulation	If set, no x87 floating-point unit present, if clear, x87 FPU present
    TS = 0x08, // Task switched	Allows saving x87 task context upon a task switch only after x87 instruction used
    ET = 0x10, // Extension type	On the 386, it allowed to specify whether the external math coprocessor was an 80287 or 80387
    NE = 0x20, // Numeric error	Enable internal x87 floating point error reporting when set, else enables PC style x87 error detection
    WP = 0x010000, // Write protect	When set, the CPU can't write to read-only pages when privilege level is 0
    AM = 0x040000, // Alignment mask	Alignment check enabled if AM set, AC flag (in EFLAGS register) set, and privilege level is 3
    NW = 0x20000000, // Not-write through	Globally enables/disable write-through caching
    CD = 0x40000000, // Cache disable	Globally enables/disable the memory cache
    PG = 0x80000000, // Paging	If 1, enable paging and use the CR3 register, else disable paging.
};

enum CR4Flags {
    VME = 0x01, // Virtual 8086 Mode Extensions	If set, enables support for the virtual interrupt flag (VIF) in virtual-8086 mode.
    PVI = 0x02, // Protected-mode Virtual Interrupts	If set, enables support for the virtual interrupt flag (VIF) in protected mode.
    TSD = 0x04, // Time Stamp Disable	If set, RDTSC instruction can only be executed when in ring 0, otherwise RDTSC can be used at any privilege level.
    DE = 0x08, // Debugging Extensions	If set, enables debug register based breaks on I/O space access.
    PSE = 0x10, // Page Size Extension	If unset, page size is 4 KiB, else page size is increased to 4 MiB. If PAE is enabled or the processor is in x86-64 long mode this bit is ignored.
    PAE = 0x20, // Physical Address Extension	If set, changes page table layout to translate 32-bit virtual addresses into extended 36-bit physical addresses.
    MCE = 0x40, // Machine Check Exception	If set, enables machine check interrupts to occur.
    PGE = 0x80, // Page Global Enabled	If set, address translations (PDE or PTE records) may be shared between address spaces.
    PCE = 0x0100, // Performance-Monitoring Counter enable	If set, RDPMC can be executed at any privilege level, else RDPMC can only be used in ring 0.
    OSFXSR = 0x0200, // Operating system support for FXSAVE and FXRSTOR instructions	If set, enables Streaming SIMD Extensions (SSE) instructions and fast FPU save & restore.
    OSXMMEXCPT = 0x0400, // Operating System Support for Unmasked SIMD Floating-Point Exceptions	If set, enables unmasked SSE exceptions.
    UMIP = 0x0800, // User-Mode Instruction Prevention	If set, the SGDT, SIDT, SLDT, SMSW and STR instructions cannot be executed if CPL > 0.
    LA57 = 0x1000, // If set, enables 5-Level Paging.
    VMXE = 0x2000, // Virtual Machine Extensions Enable	see Intel VT-x x86 virtualization.
    SMXE = 0x400, // Safer Mode Extensions Enable	see Trusted Execution Technology (TXT)
    FSGSBASE = 0x010000, // Enables the instructions RDFSBASE, RDGSBASE, WRFSBASE, and WRGSBASE.
    PCIDE = 0x020000, // PCID Enable	If set, enables process-context identifiers (PCIDs).
    OSXSAVE = 0x040000, // XSAVE and Processor Extended States Enable	
    SMEP = 0x100000, // Supervisor Mode Execution Protection Enable	If set, execution of code in a higher ring generates a fault.
    SMAP = 0x200000, // Supervisor Mode Access Prevention Enable	If set, access of data in a higher ring generates a fault.
    PKE = 0x400000, // Protection Key Enable	See Intel 64 and IA-32 Architectures Software Developer’s Manual.
};

void setCR0(uint_32 value);
void setCR2(uint_32 value);
void setCR3(uint_32 value);
void setCR4(uint_32 value);

uint_32 getCR0();
uint_32 getCR2();
uint_32 getCR3();
uint_32 getCR4();