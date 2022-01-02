;ssize_t ft_read(int fd, void *buf, size_t count)
;extern int *__error(void); #define errno (*__error())
    global _ft_read
    extern ___error
segment .text
_ft_read :
    mov     rax, 0x2000003; read syscall #num
    syscall
    jnc     done
handle_err :
    push    rax
    call    ___error
    pop     qword [rax]
    mov     rax, -1
done :
    ret
