;
; Read sectors from given drive, starting from the second sector of the first track of the first cylinder
;
; ES:BX = Buffer Address
; AL = Sectors to read
; DL = Drive
read_drive:
    push bp
    mov bp, sp

    mov bl, al

    mov ah, 2
    mov cl, 2
    mov ch, 0
    mov dh, 0

    int 0x13
    jc read_drive_general_error
    
    cmp bl, al
    jne read_drive_partial_read_error

    jmp read_drive_return

read_drive_general_error:
    push ax
    mov ax, READ_DRIVE_GENERAL_ERROR
    call print
    pop ax
    shr ax, 8
    mov dx, ax
    call print_hex
    mov ax, EMPTY_STRING
    call println
    jmp read_drive_return

read_drive_partial_read_error:
    push ax
    mov ax, READ_DRIVE_PARTIAL_READ_ERROR
    call print
    pop ax
    shr ax, 8
    mov dx, ax
    call print_hex
    mov ax, EMPTY_STRING
    call println
    jmp read_drive_return

read_drive_return:
    pop bp
    ret


READ_DRIVE_GENERAL_ERROR:
    db "Failed to read from drive! Error code: ", 0

READ_DRIVE_PARTIAL_READ_ERROR:
    db "Failed to read all sectors requested! Actual number of sectors read: ", 0