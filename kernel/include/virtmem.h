#include<types.h>

// typedef struct PageDirectoryEntry {
//     uint_8 flags;
//     uint_8 pageTableAddrL; // 20 bit address, the lower 4 bits (on bits 7-4)
//     uint_16 pageTableAddrH; // 20 bit address, the higher 16 bits (whole uint_16)
// } __attribute__((packed)) PageDirectoryEntry;

enum class PageDirectoryEntryFlags {
    Present = 0x01, // in physical memory if set
    RW = 0x02, // read-write if set, read-only otherwise
    User = 0x04, // if set the page can be accessed by all priviledge levels, if not set only supervisor. // TODO: what priviledge level is that? 0 prob?
    WriteThrough = 0x08, // if set write-through caching is enabled, otherwise write-back is enabled.
    DisableCache = 0x10, // if set, don't cache the page
    Accessed = 0x20,
    // 0x40 isn't used (always 0)
    PageSize = 0x80 // 4 MiB if set, 4 KiB otherwise 
};

// typedef struct PageTableEntry {
//     uint_8 flags;
//     uint_8 globalFlagPageFrameAddrL; // physical 20 bit address, the lower 4 bits (on bits 7-4), bit 0 is the Global flag which when set prevents the TLB from updating if CR3 is reset
//     uint_16 pageFrameAddrH; // physical 20 bit address, the higher 16 bits (whole uint_16)
// } __attribute__((packed)) PageTableEntry;

enum class PageTableEntryFlags {
    Present = 0x01, // in physical memory if set
    RW = 0x02, // read-write if set, read-only otherwise
    User = 0x04, // if set the page can be accessed by all priviledge levels, if not set only supervisor. // TODO: what priviledge level is that? 0 prob?
    WriteThrough = 0x08, // if set write-through caching is enabled, otherwise write-back is enabled.
    CacheDisabled = 0x10, // if set, cache is disabled (like the DisableCache in page directory entries)
    Accessed = 0x20,
    Dirty = 0x40, // if the bit has been written to
    // 0x80 isn't used if PAT is not supported (so always 0)
    Global = 0x100 // if set, prevents the TLB from updating the address in its cache if CR3 is reset. Note, that the page global enable bit in CR4 must be set to enable this feature
};

void enableVirtualMemory();