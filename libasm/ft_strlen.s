	global _ft_strlen; int ft_strlen(char *s1)
section .text
_ft_strlen :
	sub	rax, rax; the mov inst costs more byte than sub or xor, int rax = 0
	jmp	counting_loop
counting_loop :
	cmp	BYTE [rdi + rax], 0x0
	je	done; jz, str[rax] == 0
	inc	rax; rax++
	jmp	counting_loop
done :
	ret; return rax;
