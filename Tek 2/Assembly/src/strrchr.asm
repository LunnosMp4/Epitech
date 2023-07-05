; EPITECH PROJECT, 2022
; Assembly
; File description:
; strrchr.asm

section .text
    global _strrchr

_strrchr:
    push rbp ; Save the base pointer
    mov rbp, rsp ; Set the base pointer to the stack pointer
    mov rcx, 0 ; Set index register to 0

.loop:
    cmp byte [rdi], 0 ; Check if the current char is the null terminator
    je .exit ; If it is, exit the loop
    cmp byte [rdi], sil ; Check if the current char is the one we are looking for
    jne .found
    mov rcx, rdi ; If it is, save the index in rax

.found:
    inc rdi ; Increment the index (we are looking for the last occurence)
    jmp .loop

.exit:
    mov rax, rcx ; Return the string starting at the index
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
    ret