; EPITECH PROJECT, 2022
; Assembly
; File description:
; strncmp.asm

section .text
    global _strncmp

_strncmp:
    push rbp ; Save the base pointer
    mov rbp, rsp ; Set the base pointer to the stack pointer
    mov eax, 0 ; Set the return value to 0
    mov rcx, 0 ; Set the counter to 0

.loop:
	cmp rdx, rcx ; Check if the counter is greater than the length
	je .exit ; If so, exit the function
	mov bl, BYTE [rdi + rcx] ; Get the current character of the first string
	mov r8b, BYTE [rsi + rcx] ; Get the current character of the second string
	cmp bl, r8b ; Compare the two characters
	je .continue ; If they are the same, continue
    jmp .found ; If they are different, return the difference

.continue:
	cmp bl, 0 ; Check if the current character is the null terminator
	je .exit ; If so, exit the function
	inc rcx ; Increment the counter
    jmp .loop

.found:
	movsx eax, bl ; Convert the first character to an integer
	movsx ebx, r8b ; Convert the second character to an integer
	sub eax, ebx ; Subtract the second character from the first
    jmp .exit

.exit:
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
	ret