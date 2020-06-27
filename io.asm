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