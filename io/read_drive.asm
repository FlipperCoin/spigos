;
; Read sectors from given drive, starting from the second sector of the first track of the first cylinder
;
; ES:BX = Buffer Address
; AL = Sectors to read
; DL = Drive
read_drive:
    push bp
    mov bp, sp

    push ax ; Save sectors to read

    mov ah, 2 ; Read sectors from drive function table index
    mov cl, 2 ; Second sector
    mov ch, 0 ; First cylinder
    mov dh, 0 ; First head

    int 0x13
    jc read_drive_general_error
    
    pop bx
    cmp bl, al ; Read same number of requested sectors
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