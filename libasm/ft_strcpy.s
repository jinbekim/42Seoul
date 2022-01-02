	global _ft_strcpy; char *ft_strcpy(char *s1, char *s2)

segment .text
_ft_strcpy :
	push rcx; backup register data
	push rbx; backup register data
	sub	rcx, rcx; index i = 0
	cmp	rsi, 0; if (!s2)
	je	cpy_end
cpy_loop :; s1[i] = s2[i]
	mov	bl, byte [rsi + rcx]
	mov	byte [rdi + rcx], bl
null_check :; while(s2[i] != 0) i++
	inc	rcx
	cmp	bl, 0
	jne	cpy_loop
cpy_end :
	mov rax, rdi
	pop rcx
	pop rbx
	ret