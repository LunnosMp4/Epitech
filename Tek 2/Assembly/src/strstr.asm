; EPITECH PROJECT, 2022
; Assembly
; File description:
; strstr.asm

section .text
    global _strstr

_strstr:
    push rbp ; Save the base pointer
    mov rbp, rsp ; Set the base pointer to the stack pointer
    mov rbx, 0 ; set index of string2 to 0

.loop:
    mov r8, rbx ; copy index of string2 into index copy
    mov rcx, 0 ; set index of string1 to 0

.sub_loop:
    mov dl, byte [rsi + rcx] ; move the byte at string1 + index counter into dl
    cmp dl, 0 ; compare dl to 0
    je .found ; if equal, we found the string
    mov al, byte [rdi + r8] ; move the byte at string2 + index copy into al
    cmp al, 0 ; compare al to 0
    je .not_found ; if equal, we didn't find the string and reached the end of string1
    cmp al, dl ; compare al to dl
    jne .continue ; if not equal, we didn't find the string
    inc r8 ; increment index copy of string2
    inc rcx ; increment index of string1
    jmp .sub_loop

.continue:
    inc rbx ; increment index of string2
    jmp .loop ; goto .loop

.not_found:
    mov rax, 0 ; set return value to null
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
    ret

.found:
    mov rax, rdi ; set return value to rdi
    add rax, rbx ; add index to return value
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
    ret