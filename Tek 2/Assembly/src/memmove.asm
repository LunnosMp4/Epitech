; EPITECH PROJECT, 2022
; Assembly
; File description:
; memmove.asm

section .text
    global _memmove

_memmove:
    push rbp ; Save the base pointer
    mov rbp, rsp ; Set the base pointer to the stack pointer
    mov rcx, 0 ; Set counter register to 0

.loop:
    cmp rcx, rdx ; Compare the counter with the length of data
    je .exit
    mov al, byte [rsi + rcx]; move a byte from source to destination
    mov byte [rdi + rcx], al ; store the byte in destination
    inc rcx ; Increment the counter
    jmp .loop

.exit:
    mov rax, rdi ; Return the destination
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
    ret
