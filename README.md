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

## Credits  
I would have never been able to get this project started without Nick Blundell's "*Writing a Simple Operating System - from Scratch*".  
I also used [OSDev](https://wiki.osdev.org/Main_Page)'s great material, which helped a **lot** (especially after reaching the end of Nich Blundell's book).