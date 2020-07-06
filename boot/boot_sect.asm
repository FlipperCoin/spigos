[org 0x7c00]
KERNEL_OFFSET equ 0x1000

real_mode:
    mov bp, 0x9000      ; set the stack
    mov sp, bp

    mov [BOOT_DRIVE], dl

    mov ah, 0x00        ; clear screen
    mov al, 0x03        ; text mode 80x25 16 colours
    int 0x10

    call load_kernel
    call switch_to_pm

load_kernel:
    push ebp
    mov ebp, esp

    mov bx, KERNEL_OFFSET
    mov al, 15
    mov dl, [BOOT_DRIVE]
    call read_drive

    leave
    ret

BOOT_DRIVE:
    db 0

%include "switch_to_pm.asm"
%include "io.asm"

[bits 32]
boot_main:

    call KERNEL_OFFSET ; KernelMain
    
    jmp $

; bootsector padding
times 510-($-$$) db 0
dw 0xAA55