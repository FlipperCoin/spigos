%include "copy_str.asm"

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
    

HEX_OUT:
    db '0x0000',0

HEX_OUT_DEFAULT:
    db '0x0000',0