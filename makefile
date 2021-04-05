# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 02:51:58 by jinbekim          #+#    #+#              #
#    Updated: 2021/04/04 14:41:37 by jinbekim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3D
INC = -Iincludes/
MLX = -L./mlx_beta -lmlx
LIBFT = -lft -L./libft
SRC = main.c \
	parse_config.c \
	parse_config2.c \
	parse_config3.c \
	error_exit.c \
	key_control.c \
	game_close.c \
	mouse_move.c \
	wall.c \
	wall2.c \
	floor_ceil.c \
	init_ptr.c \
	sprite.c \
	sprite2.c \
	screenshot.c

BNS = $(addsuffix _bonus.c, $(basename $(SRC))) key_control2_bonus.c

# %.o : src/%.c
# 	$(CC) $(CFLAGS) $(INC) -c -o $@ $?

# OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(addprefix ./src/, $(SRC))
	$(MAKE) -C ./libft
	$(CC) -Werror -Wextra -Wall -fsanitize=address $(MLX) $(LIBFT) $(INC) $^ -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(addprefix ./bonus/, $(BNS))
	$(MAKE) -C ./libft
	$(CC) -Wall -Werror -Wextra $(MLX) $(LIBFT) $(INC) $^ -o $(NAME)

.PHONY : all clean fclean re bonus
