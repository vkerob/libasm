bits 64

extern malloc
extern ft_strlen

section .text
global ft_strdup
	; parameters
	; rdi = string to duplicate

	ft_strdup:
		cmp rdi, 0
		je error
		
		call ft_strlen				; -> return value are in rax
		inc rax
		push rdi					; save rdi(s)
		mov rdi, rax				; rdi = rax for malloc

		call malloc wrt ..plt		; -> return value in rax, pointeur to the space allocate on sucess
		cmp rax, 0
		je error

		pop rdi						; restore rdi

		xor rcx, rcx
		xor rdx, rdx
	copy:
		mov dl, BYTE [rdi + rcx]
		mov BYTE [rax + rcx], dl
		cmp dl, 0
		jz end
		inc rcx
		jmp copy

	end:
		ret

	error:
		xor rax, rax
		ret
