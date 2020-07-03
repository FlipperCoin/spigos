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
call println

mov bx, 0x9000
mov al, 1
mov dl, [BOOT_DRIVE]
call read_drive

mov dx, [0x9000]
call print_hex
mov ax, EMPTY_STRING
call println

mov dx, [0x9100]
call print_hex
mov ax, EMPTY_STRING
call println

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

times 256 db 0xFA, 0xCE
times 256 db 0xBE, 0xEF