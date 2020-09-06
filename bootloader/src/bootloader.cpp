#define KERNEL_ADDR 0x10000
#define KERNEL_FIRST_LBA_BLOCK 55

#if !defined(KERNEL_SIZE)
#error KERNEL_SIZE directive required
#endif

void ataRead(unsigned int lbaBlock, unsigned char sectorCount, unsigned char *buffer);

extern "C" void BootloaderMain() {
    auto kernelAddr = (unsigned char *)KERNEL_ADDR;
    ataRead(KERNEL_FIRST_LBA_BLOCK, KERNEL_SIZE, kernelAddr);
    
    auto kernelEntry = (int (*)())kernelAddr;
    kernelEntry();
}