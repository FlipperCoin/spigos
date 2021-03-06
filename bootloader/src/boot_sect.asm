[bits 16]
[org 0x7c00]
BOOTLOADER_OFFSET equ 0x1000
real_mode:
    mov bp, 0x9000      ; set the stack
    mov sp, bp

    mov [BOOT_DRIVE], dl

    mov ah, 0x00        ; clear screen
    mov al, 0x03        ; text mode 80x25 16 colours
    int 0x10

    mov ax, REAL_MODE_MSG
    call println

    call load_bootloader
    call switch_to_pm

load_bootloader:
    push bp
    mov bp, sp

    mov bx, BOOTLOADER_OFFSET
    mov al, 54
    mov dl, [BOOT_DRIVE]
    call read_drive

    pop bp
    ret

BOOT_DRIVE:
    db 0
REAL_MODE_MSG:
    db "Real Mode", 0

%include "pm/switch_to_pm.asm"
%include "rm/io/io.asm"
%include "pm/print.asm"

[bits 32]
boot_main:

    push PROTECTED_MODE_MSG
    call print_pm

    call BOOTLOADER_OFFSET 
    
    jmp $

PROTECTED_MODE_MSG:
    db "Protected Mode", 0

; bootsector padding
times 510-($-$$) db 0
dw 0xAA55