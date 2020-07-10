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
3. Install virtualization software for an x86 architecture.  
    I used QEMU but you can use other virtualization software.  
    On Debian based:
    ```bash
    sudo apt install qemu
    ```  
    On Windows (64 bit) download & install [here](https://qemu.weilnetz.de/w64).

## Run
Compile using make:
```bash
make
```
Running with QEMU (using default 'out' dir):
```bash
qemu-system-i386 out/spigos_img
```
That's it!