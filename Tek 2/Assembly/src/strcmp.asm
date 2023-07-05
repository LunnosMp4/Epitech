; EPITECH PROJECT, 2022
; Assembly
; File description:
; strcmp.asm

section .text
    global _strcmp

_strcmp:
    push rbp ; Save base pointer on the stack
    mov rbp, rsp ; Move the stack pointer to the base pointer
    mov rcx, 0 ; Initialize a counter to 0

.loop:
    mov al, byte [rsi + rcx] ; Load the next character from the first string
    mov dl, byte [rdi + rcx] ; Load the next character from the second string
    cmp al, dl ; Compare the two characters
    jne .exit ; If they are different, return the difference
    cmp al, 0 ; If the characters are 0, they are equal
    je .exit ; If they are equal, return 0
    inc rcx ; Increment the counter
    jmp .loop

.exit:
    sub rax, rdx ; Return the difference between the two characters
    neg rax ; Invert the result
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
    ret
