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

format_hex:
    push bp
    mov bp, sp
    push dx

    push HEX_OUT_DEFAULT
    push HEX_OUT
    call copy_str
    add sp, 4

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
    pop bp
    ret
    
copy_str:
    push bp
    mov bp, sp
    push bx
    push cx
    push dx
    mov cx, 0
copy_str_loop:
    mov bx, bp ; src
    mov bx, [bx]
    add bx, cx
    mov dl, [bx]
    cmp dl, 0
    je copy_str_exit
    mov bx, bp ; dst
    lea bx, [bx + 2]
    mov bx, [bx]
    add bx, cx
    mov [bx], dl
    inc cx
    jmp copy_str_loop
copy_str_exit:
    pop dx
    pop cx
    pop bx
    pop bp
    ret


NEW_LINE:
    db 0x0d,0x0a,0

HEX_OUT:
    db '0x0000',0

HEX_OUT_DEFAULT:
    db '0x0000',0