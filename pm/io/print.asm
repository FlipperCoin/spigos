%include "format_hex.asm"

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

print:
    pusha
    mov ebx, eax ; string pointer
    mov dl, WHITE_ON_BLACK
    mov cx, 0
print_loop:
    mov dh, [ebx]
    cmp dh, 0
    je print_exit
    mov bx, cx
    lea ebx, [VIDEO_MEMORY + bx]
    mov [ebx], ax
    add cx, 2
    inc eax
    mov ebx, eax
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