#define KERNEL_ADDR 0x10000
#define KERNEL_FIRST_LBA_BLOCK 55

#if !defined(KERNEL_SIZE)
#error KERNEL_SIZE directive required
#endif

void ataRead(unsigned int lbaBlock, unsigned char sectorCount, unsigned char *buffer);
void print(char *msg);

extern "C" void BootloaderMain() {
    print("Bootloader 2nd boot sequence.");
    
    auto kernelAddr = (unsigned char *)KERNEL_ADDR;
    ataRead(KERNEL_FIRST_LBA_BLOCK, KERNEL_SIZE / 512, kernelAddr);
    
    auto kernelEntry = (int (*)())kernelAddr;
    kernelEntry();
}