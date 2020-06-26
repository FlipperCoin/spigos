mov ah, 0x0e    ; scrolling teletype BIOS routine

mov cx, 0
mov bx, hello
add bx, 0x7c00
print_hello:
    mov al, [bx]
    int 0x10
    inc cx
    inc bx
    cmp cx, 5
    jne print_hello

jmp $

hello:
    db 'HELLO'

times 510-($-$$) db 0

dw 0xAA55