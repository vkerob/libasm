bits 64

extern __errno_location

section .text
global ft_read
	; parameters
	; rdi = file descriptor
	; rsi = buffer
	; rdx = count

	ft_read:

		mov rcx, rdx
		sub rcx, 1
		cmp rsi, 0
		je error_bad_address

	init_buf:
		mov BYTE [rsi + rcx], 0
		sub rcx, 1
		cmp rcx, 0
		jge init_buf

		mov rax, 0
		syscall

		cmp	rax, 0
		js	error_syscall

		ret

	error_bad_address:
        mov edi, 14							; EFAULT
        call __errno_location wrt ..plt
        mov [rax], edi
        mov rax, -1
        ret


	error_syscall:

		mov rdi, rax
        neg rdi
        call __errno_location wrt ..plt
        mov [rax], edi
        mov rax, -1
        ret