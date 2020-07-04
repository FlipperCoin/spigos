;
; Init data segment
;
mov bx, 0x7c0
mov ds, bx

;
; Init stack
;
mov bp, 0x8000
mov sp, bp

mov [BOOT_DRIVE], dl

;
; Clear screen
;
mov ah, 0x00
mov al, 0x03 ; text mode 80x25 16 colours
int 0x10

mov ax, BOOT_WELCOME
call print

jmp $

%include "io.asm"

BOOT_WELCOME:
    db 'Hello, Bootloader!',0

BOOT_DRIVE:
    db 0

EMPTY_STRING:
    db 0

times 510-($-$$) db 0

dw 0xAA55