; EPITECH PROJECT, 2022
; Assembly
; File description:
; strlen.asm

section .text
    global _strlen

_strlen:
    push rbp ; Save the base pointer
    mov rbp, rsp ; Set the base pointer to the stack pointer
    mov rcx, 0 ; Set counter register to 0

.loop:
    cmp byte [rdi + rcx], 0 ; Check if the current byte is 0 (end of string)
    je .exit ; If it is, exit the loop
    inc rcx ; Else, increment counter
    jmp .loop

.exit:
    mov rax, rcx ; Set the return value to the counter
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
    ret
