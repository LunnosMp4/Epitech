; EPITECH PROJECT, 2022
; Assembly
; File description:
; memset.asm

section .text
    global _memset

_memset:
    push rbp ; Save the base pointer
    mov rbp, rsp ; Set the base pointer to the stack pointer
    mov rcx, 0 ; Set counter register to 0

.loop:
    cmp rcx, rdx ; Compare the counter to the length
    je .exit ; If it is, exit the loop
    mov byte [rdi + rcx], sil ; Else set the current byte in the memory to the value (sil)
    inc rcx ; Increment counter index
    jmp .loop

.exit:
    mov rax, rdi ; Return the destination
    mov rsp, rbp ; Restore the stack pointer
    pop rbp ; Restore the base pointer
    ret