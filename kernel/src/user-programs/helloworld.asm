SECTION .TEXT
    GLOBAL hello_world

hello_world:
    jmp main

msg:
    db "Hello World!",0x0a,0

main:
    mov ecx, 13 ; size
    mov ebx, 0x4000+msg ; buf
    mov eax, 4 ; write
    int 0x80

    mov ebx, 500 ; ms
    mov eax, 162 ; sleep
    int 0x80

    jmp main