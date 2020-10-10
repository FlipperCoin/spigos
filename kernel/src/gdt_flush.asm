SECTION .TEXT
    GLOBAL gdt_flush

KERNEL_CODE equ 0x08
KERNEL_DATA equ 0x10

gdt_flush:
    mov eax, [esp + 4]
    lgdt [eax]

    mov eax, cr0
    or eax, 0x01
    mov cr0, eax
    
    mov ax, KERNEL_DATA
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    jmp KERNEL_CODE:flush

flush:
    ret
