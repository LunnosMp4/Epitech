; EPITECH PROJECT, 2022
; Assembly
; File description:
; strchr.asm

section .text
    global _strchr

_strchr:
    push rbp ; Save the base pointer
    mov rbp, rsp ; Set the base pointer to the stack pointer
    mov rcx, 0 ; Set index register to 0

.loop:
    cmp byte [rdi + rcx], sil ; Check if the current char is the one we're looking for
    je .exit ; If it is, we exit the loop
    cmp byte [rdi + rcx], 0 ; Check if the current char is the null terminator
    je .exit_not_found ; If it is, we return 0
    inc rcx ; If not, we increment the index
    jmp .loop

.exit:
    lea rcx, [rdi + rcx] ; Return the string starting at the index
    mov rax, rcx ; Return the string starting at the index
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
    ret

.exit_not_found:
    mov rax, 0 ; Return 0
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
    ret