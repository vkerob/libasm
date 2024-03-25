bits 64

section .text
global ft_strcmp
	; parameters
	; rdi = s1
	; rsi = s2

	ft_strcmp:
		cmp rdi, 0
        je check_s2
		xor rcx, rcx
        jmp start_loop

	check_s2:
        cmp rsi, 0
        jne start_loop
        xor rax, rax
        ret

	start_loop:
		mov	al, BYTE [rdi + rcx]
		mov	dl, BYTE [rsi + rcx]			; BYTE != bits, BYTE == octet

	loop_compare:
		cmp al, 0
		je	s1_empty_inf
		cmp dl, 0
		je	s2_empty_sup
		cmp al, dl
		jne end_unknow_diff					; s1[rcx] != s2[rcx]
		inc rcx
		jmp start_loop
		

	s1_empty_inf:
		mov		al, dl
		movzx	rax, al
		neg		rax
		ret

	s2_empty_sup:
		movzx	rax, al
		ret

	end_unknow_diff:
		movzx	rax, al
        movzx	rdx, dl
        sub		rax, rdx
		ret
