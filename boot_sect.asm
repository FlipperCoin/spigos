[org 0x7c00]

;
; Initialize the stack
;
mov bp, 0x8000
mov sp, bp

;
; Clear screen
;
mov ah, 0x00
mov al, 0x03 ; text mode 80x25 16 colours
int 0x10

mov ax, hello
call print
mov dx, 0x12AB
call print_hex

jmp $

%include "io.asm"

hello:
    db 'Hello, Bootloader!',0

times 510-($-$$) db 0

dw 0xAA55