[bits 32]

%include "format_hex.asm"

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

print:
    pusha
    mov ebx, eax ; string pointer
    mov edx, VIDEO_MEMORY
    mov ah, WHITE_ON_BLACK
print_loop:
    mov al, [ebx]
    cmp al, 0
    je print_exit
    mov [edx], ax
    inc ebx
    add edx, 2
    jmp print_loop
print_exit:
    popa
    ret

print_hex:
    pusha
    call format_hex
    call print
    popa
    ret