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

print_hex:
    pusha
    call format_hex
    call print
    popa
    ret

format_hex:
    push ebp
    mov ebp, esp
    push dx

    mov cx, dx
    lea bx, [HEX_OUT + 5]
format_hex_loop:
    mov ax, cx
    and ax, 0x0F
    cmp ax, 0x09
    jle format_hex_below9
format_hex_above9:
    add al, 55
    jmp format_hex_commit
format_hex_below9:
    add al, 48
format_hex_commit:
    mov [bx], al
    dec bx
    shr cx, 4
    cmp cx, 0 ; happens before bx is out of range because dx is 16 bit
    jne format_hex_loop

    mov ax, HEX_OUT
    pop dx
    pop ebp
    ret
    

HEX_OUT:
    db '0x0000',0