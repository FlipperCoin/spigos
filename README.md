# SpigOS
A minimal OS developed by me for educational purposes & personal practice
## Requirements
Do the following:  
1. Install make.  
    ```bash
    sudo apt install make
    ```
2. Install nasm.  
    ```bash
    sudo apt install nasm
    ```
3.  Install virtualization software for an x86_64 architecture.  
    I used QEMU but in theory you can use other virtualization software if BIOS will have the same behaviour.  
    On Debian based:
    ```bash
    sudo apt install qemu
    ```  
    On Windows (64 bit) download & install [here](https://qemu.weilnetz.de/w64).

## Running
Compile using make:
```bash
make
```
Running with QEMU (using default 'out' dir):
```bash
qemu-system-x86_64 out/boot_sect.bin
```
That's it!