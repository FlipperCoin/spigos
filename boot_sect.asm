;
; Initialize data and stack segment
;
mov bx, 0x7c0
mov ds, bx
mov bx, 0x800
mov ss, bx

;
; Clear screen
;
mov ah, 0x00
mov al, 0x03 ; text mode 80x25 16 colours
int 0x10

mov ax, HELLO
call println
mov dx, 0x12AB
call print_hex
push 0
mov ax, sp
call println

jmp $

%include "io.asm"

HELLO:
    db 'Hello, Bootloader!',0

times 510-($-$$) db 0

dw 0xAA55