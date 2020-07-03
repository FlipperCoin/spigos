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