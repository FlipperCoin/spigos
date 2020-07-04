[bits 16]
switch_to_pm:
    cli                         ; switch off interrupts
    
    lgdt [gdt_descriptor]       ; load GDT descriptor
    
    mov eax, cr0                ; set first bit of CR0 to switch to protected mode
    or eax, 0x01
    mov cr0, eax

    jmp CODE_SEG:protected_mode ; far jump to 32 bit code with flushed CPU pipeline & set CS

[bits 32]
protected_mode:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    
    mov ebp, 0x90000
    mov esp, ebp

    call boot_main

%include "gdt.asm"
