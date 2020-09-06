[bits 32]

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

print_pm:
    pusha
    mov ebx, eax ; string pointer
    mov edx, VIDEO_MEMORY
    mov ah, WHITE_ON_BLACK
print_pm_loop:
    mov al, [ebx]
    cmp al, 0
    je print_pm_exit
    mov [edx], ax
    inc ebx
    add edx, 2
    jmp print_pm_loop
print_pm_exit:
    popa
    ret