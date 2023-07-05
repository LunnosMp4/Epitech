; EPITECH PROJECT, 2022
; Assembly
; File description:
; strcmp.asm

section .text
    global _strcasecmp

_strcasecmp:
    push rbp ; Save base pointer on the stack
    mov rbp, rsp ; Move the stack pointer to the base pointer
    mov rcx, 0 ; Initialize a counter to 0

.loop:
    mov al, byte [rsi + rcx] ; Load the next character from the first string
    mov dl, byte [rdi + rcx] ; Load the next character from the second string
    cmp al, 65 ; Compare the character to 'A'
    jl .check_second_string ; If it is lower, skip the next instruction
    cmp al, 90 ; Compare the character to 'Z'
    jg .check_second_string ; If it is higher, skip the next instruction
    add al, 32 ; If it is between 'A' and 'Z', add 32 to it
    jmp .check_second_string

.check_second_string:
    cmp dl, 65 ; Compare the character to 'A'
    jl .strcmp ; If it is lower, skip the next instruction
    cmp dl, 90 ; Compare the character to 'Z'
    jg .strcmp ; If it is higher, skip the next instruction
    add dl, 32 ; If it is between 'A' and 'Z', add 32 to it
    jmp .strcmp

.strcmp:
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