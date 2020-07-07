[bits 16]
format_hex:
    push bp
    mov bp, sp

    push dx
    
    mov cx, dx
    lea dx, [HEX_OUT + 1]
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
    shr cx, 4
    dec bx
    cmp bx, dx
    jne format_hex_loop

    mov ax, HEX_OUT
    pop dx
    pop bp
    ret
    

HEX_OUT:
    db "0x0000",0