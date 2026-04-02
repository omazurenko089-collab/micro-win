; micro-win OS Bootloader
; 16-bit real mode bootloader

[ORG 0x7C00]
[BITS 16]

start:
    jmp boot

boot:
    mov ax, 0
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    
    mov si, msg
    call print_string
    
    mov ah, 0x13
    mov al, 1
    mov bh, 0
    mov bl, 0x0A
    mov cx, 20
    mov dh, 10
    mov dl, 30
    mov bp, msg
    int 0x10
    
    hlt

print_string:
    lodsb
    cmp al, 0
    je .done
    mov ah, 0x0E
    int 0x10
    jmp print_string
.done:
    ret

msg db 'micro-win OS', 0

times 510-($-$$) db 0
dw 0xAA55