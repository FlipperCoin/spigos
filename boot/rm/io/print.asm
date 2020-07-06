%include "format_hex.asm"

print:
    pusha
    mov bx, ax ; string pointer
    mov ah, 0x0E ; Write TTY
print_loop:
    mov al, [bx]
    cmp al, 0
    je print_exit
    int 0x10
    inc bx
    jmp print_loop
print_exit:
    popa
    ret

println:
    pusha
    call print
    mov ax, NEW_LINE
    call print
    popa
    ret

print_hex:
    pusha
    call format_hex
    call print
    popa
    ret



NEW_LINE:
    db 0x0d,0x0a,0