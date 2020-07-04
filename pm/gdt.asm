gdt_start:          ; Start of GDT

gdt_null:           
    times 2 dd 0x0  ; Null entry

gdt_code:
    dw 0xFFFF       ; Limit 0:15
    dw 0x0000       ; Base 0:15
    db 0x00         ; Base 16:23
    db 10011010b    ; (Present)1 (Privl)00 (S)1 (Ex)1 (DC)0 (RW)1 (Ac) 0
    db 11001111b    ; Flags (Gr)1 (Sz)1, Limit 16:19
    db 0x00         ; Base 24:31

gdt_data:
    dw 0xFFFF       ; Limit 0:15
    dw 0x0000       ; Base 0:15
    db 0x00         ; Base 16:23
    db 10010010b    ; (Present)1 (Privl)00 (S)1 (Ex)0 (DC)0 (RW)1 (Ac) 0
    db 11001111b    ; Flags (Gr)1 (Sz)1, Limit 16:19
    db 0x00         ; Base 24:31

gdt_end:            ; For size of GDT calculation


gdt_descriptor:
    dw gdt_end - gdt_start - 1  ; Size substructed by 1
    dd gdt_start                ; Offset

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start