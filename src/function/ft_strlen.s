bits 64

section .text	
global ft_strlen
	; parameters
	; rdi = char *str

	ft_strlen:
		xor rax, rax		; rax = 0

	loop:
		cmp BYTE [rdi + rax], 0
		je end
		inc rax
		jmp loop

	end:
		ret