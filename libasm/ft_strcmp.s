	global _ft_strcmp; int ft_strcmp(char *s1, char *s2)

segment .text
_ft_strcmp :
	push rcx; backup data
	push rbx; backup data
	sub	rcx, rcx; index i
	cmp	rdi, 0; null check
	jz	func_return; !s1
	cmp	rsi, 0 ; null check
	jz	func_return; !s2
	jmp	loop_cond; start loop

loop_cond :; while (!(*s1) && !(*s2))
	mov	bl, byte [rdi + rcx]
	cmp	bl, 0
	je	loop_end
	mov	bl, byte [rsi + rcx]
	cmp bl, 0
	je	loop_end
	jmp	compare_loop

compare_loop :; if (s1[i] == s2[i])
	mov	bl, byte [rdi + rcx]
	cmp	bl, byte [rsi + rcx]
	jne loop_end
	inc	rcx
	jmp	loop_cond

loop_end :
	mov	bl, byte [rdi + rcx]
	cmp	bl, byte [rsi + rcx]
	je	equal
	jb	s2bigger
	jmp	s1bigger

func_return :
	cmp	rdi, rsi
	jb	s2bigger
	je	equal
	jmp	s1bigger
s1bigger :
	mov	rax, 1
	pop	rbx
	pop	rcx
	ret
s2bigger :
	mov	rax, -1
	pop	rbx
	pop	rcx
	ret
equal :
	mov	rax, 0
	pop	rbx
	pop	rcx
	ret
