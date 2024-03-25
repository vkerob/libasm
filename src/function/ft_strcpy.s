bits 64

section .text
global ft_strcpy
	; parameters
	; rdi = dest
	; rsi = src

	ft_strcpy:
		xor rcx, rcx


	copy:
		mov	dl, BYTE [rsi + rcx]
		mov BYTE [rdi + rcx], dl
		cmp dl, 0
		jz	return
		inc	rcx
		jmp copy

	return:
		mov rax, rdi
		ret
