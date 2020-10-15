SECTION .TEXT
    GLOBAL syscall_wrap

EXTERN syscall

; TODO: not sure if should disable interrupts or not 
; (it shouldn't from fear of registers corruption in the middle of the read because it can happen before cti)

syscall_wrap:
    pusha

    push esp ; registers
    lea eax, [esp+4*8] ; x86's interrupt frame
    push eax
    call syscall
    add esp, 8
    mov [esp+4*7], eax

    popa
    iret ; return to the caller (in user space)