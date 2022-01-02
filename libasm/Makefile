NAME = libasm.a
SRC = ft_strcmp.s ft_strcpy.s ft_strdup.s\
	ft_strlen.s ft_write.s ft_read.s
OBJ = $(SRC:.s=.o)
AR = ar rcus
AS = nasm
ASFLAGS = -fmacho64

# default
# %.o : %.s
#	$(AS) $(ASFLAGS) -o $@ $<

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $?

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : clean all

test : $(NAME)
	gcc main.c -L. -lasm && ./a.out

.PHONY : all clean fclean re test
