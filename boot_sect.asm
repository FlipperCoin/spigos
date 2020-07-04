[org 0x7c00]
real_mode:
    mov bp, 0x9000      ; set the stack
    mov sp, bp

    mov ah, 0x00        ; clear screen
    mov al, 0x03        ; text mode 80x25 16 colours
    int 0x10

    call switch_to_pm

%include "switch_to_pm.asm"
%include "io.asm"

[bits 32]
boot_main:
    mov eax, BOOT_WELCOME
    call print

    jmp $

BOOT_WELCOME:
    db 'Hello, Bootloader!',0

; bootsector padding
times 510-($-$$) db 0
dw 0xAA55