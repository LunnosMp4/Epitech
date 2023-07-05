; EPITECH PROJECT, 2022
; Assembly
; File description:
; strpbrk.asm

section .text
    global _strpbrk

_strpbrk:
    push rbp ; Save the base pointer
    mov rbp, rsp ; Set the base pointer to the stack pointer
    mov rcx, 0 ; Set the first counter to 0
    mov rbx, 0 ; Set the second counter to 0
	jmp .loop

.loop:
	mov al, byte [rdi + rbx] ; Get the first character of the first string
	cmp al, 0 ; Check if it's the end of the string
	je .exit_not_found ; If it is, exit the function
	mov rcx, 0 ; Set the second counter to 0
	jmp .second_loop

.second_loop:
	mov dl, byte [rsi + rcx] ; Get the first character of the second string
	cmp dl, 0 ; Check if it's the end of the string
	je .continue ; If it is, go to the next character of the first string
	cmp al, dl ; Check if the two characters are the same
	je .exit ; If they are, exit the function
	inc rcx ; Increment the second counter
    jmp .second_loop

.continue: ; Go to the next character of the first string
	inc rbx
    jmp .loop

.exit_not_found:
	mov rax, 0 ; Set the return value to 0
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
    ret

.exit:
	mov rax, rdi ; Set the return value to the first string
	add rax, rbx ; Add the first counter to the return value
    mov rsp, rbp ; Set the stack pointer to the base pointer
    pop rbp ; Restore the base pointer
	ret