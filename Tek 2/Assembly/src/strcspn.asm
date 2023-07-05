; EPITECH PROJECT, 2022
; Assembly
; File description:
; strcspn.asm

section .text
    global _strcspn

_strcspn:
    push rbp ; Save the base pointer
    mov rbp, rsp ; Set the base pointer to the stack pointer
	mov rbx, 0 ; Set counter register to 0
	jmp .loop

.loop: ; Loop to check the first string
	mov al, byte [rdi + rbx] ; Load the first character of the string
	cmp al, 0 ; Check if it's the end of the string
	je .exit ; If it is, exit the function
	mov rcx, 0 ; Set the counter register to 0 to check the second string
	jmp .second_loop

.second_loop: ; Loop to check the second string
	mov dl, byte [rsi + rcx] ; Load the first character of the second string
	cmp dl, 0 ; Check if it's the end of the string
	je .add ; If it is, add 1 to the counter register and check the next character of the first string
	cmp al, dl ; Check if the characters are the same
	je .exit ; If they are, exit the function
	inc rcx ; If they aren't, check the next character of the second string
    jmp .second_loop

.add:
    inc rbx
    jmp .loop

.exit:
	mov rax, rbx
    mov rsp, rbp
    pop rbp
	ret	