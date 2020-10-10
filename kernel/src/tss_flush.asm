SECTION .TEXT
    GLOBAL tss_flush

tss_flush:
    mov ax, [esp+4]
    add ax, 3 ; RPL
    ltr ax
    ret

