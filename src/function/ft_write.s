bits 64

extern __errno_location

section .text
global ft_write
	; parameters
	; rdi = file descriptor
	; rsi = buffer
	; rdx = count

	ft_write:
		mov rax, 1
		syscall

		cmp	rax, 0
		js	error

		ret

	error:

		mov rdi, rax
        neg rdi
        call __errno_location wrt ..plt
        mov [rax], edi
        mov rax, -1
        ret



