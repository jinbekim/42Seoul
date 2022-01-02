;extern int *__error(void); #define errno (*__error())
;ssize_t ft_write(int fd, const void *buf, size_t count)
    global _ft_write
    extern ___error
segment .text

_ft_write : 
    mov     rax, 0x2000004; write syscall num
    syscall
    jnc      done; if error not occured, done.
handle_err :
    push    rax; error num
    call    ___error
    pop     qword [rax]; *(error ptr) = error num
    mov     rax, -1
done :
    ret

