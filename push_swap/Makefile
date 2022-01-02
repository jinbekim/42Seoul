NAME = push_swap
B_NAME = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra
B_FUNC = main_checker.c \
	program_exit.c input_stack.c examine_sort.c \
	execute_p.c execute_r.c execute_s.c \
	execute_inst.c \
	input_inst.c rate_rank.c

FUNC = main_pushswap.c \
	program_exit.c input_stack.c examine_sort.c \
	execute_p.c execute_r.c execute_s.c execute_inst.c \
	input_inst.c rate_rank.c calculate_avrg.c\
	arrange_stack.c pb_under_avrg.c pa_over_avrg.c \
	compression_inst.c execute_inst.c init_chunk_num.c \
	arrange_small_stack.c push_sorted_chunk.c

SRCS = $(addprefix ./srcs/, $(FUNC))
OBJS = $(addprefix ./objs/, $(FUNC:.c=.o))
B_SRCS = $(addprefix ./srcs/, $(B_FUNC))
B_OBJS = $(addprefix ./objs/, $(B_FUNC:.c=.o))

INC = -I./libft/includes/ -I.
FT = ./libft/libft.a
LIBFT = -L./libft -lft
DEBUG = -O3 -g3 -fsanitize=address

./objs/%.o : ./srcs/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $?

all : $(FT) $(NAME)

$(FT) :
	$(MAKE) -C ./libft/

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(DEBUG) $^ -o $@

bonus : $(FT) $(B_NAME)

$(B_NAME) : $(B_OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(DEBUG) $^ -o $@

clean :
	rm -f $(OBJS) $(B_OBJS)
	$(MAKE) clean -C ./libft/

fclean : clean
	rm -f $(NAME) $(B_NAME)
	$(MAKE) fclean -C ./libft/

re : fclean all

.PHONY : clean fclean re bonus all
