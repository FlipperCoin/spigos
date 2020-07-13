SECTION .TEXT
    GLOBAL load_idt
    
load_idt:
    push ebp
    mov ebp, esp

    mov eax, [ebp+8]
    lidt [eax]

    leave
    ret