SECTION .TEXT
    GLOBAL switch_to_task

EXTERN currentTaskTcb

struc TCB 

  .esp:     resd   1 
  .state:   resb    1

endstruc

;   cdecl void switch_to_task(TCB *nextTask)
;   switch to the task "nextTask"
switch_to_task:
    push ebx
    push esi
    push edi
    push ebp

    mov edi, [currentTaskTcb]
    mov [edi + TCB.esp], esp    ; save current task ESP

    mov esi, [esp + (4+1)*4]    ; *nextTask 
    mov [currentTaskTcb], esi   ; set next task as current task
    
    mov esp, [esi + TCB.esp]    ; change ESP and pop state
    pop ebp
    pop edi
    pop esi
    pop ebx
    
    ret                         ; return to next task 
