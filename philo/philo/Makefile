NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra
# DEBUG = -fsanitize=address
SRC = set_env.c main.c ft_atoi.c\
	print.c pthread_branch.c monitor.c\
	routine.c ft_usleep.c

OBJ = $(SRC:.c=.o)

OBJS = $(addprefix ./objs/, $(OBJ))
INC = -I./incs/

./objs/%.o: ./srcs/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $?

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG) $(INC) -o $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
