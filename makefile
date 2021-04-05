# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 02:51:58 by jinbekim          #+#    #+#              #
#    Updated: 2021/04/05 17:17:04 by jinbekim         ###   ########.fr        #
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

BNS = $(addsuffix _bonus.c, $(basename $(SRC))) key_control2_bonus.c \
	other_bonus.c


# %.o : src/%.c
# 	$(CC) $(CFLAGS) $(INC) -c -o $@ $?

# OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(addprefix ./src/, $(SRC))
	$(MAKE) -C ./libft
	$(CC) -O3 -g3 -Werror -Wextra -Wall -fsanitize=address $(MLX) $(LIBFT) $(INC) $^ -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C ./libft fclean

re : fclean all

bonus : $(addprefix ./bonus/, $(BNS))
	$(MAKE) -C ./libft
	$(CC) -O3 -g3 -fsanitize=address -Wall -Werror -Wextra $(MLX) $(LIBFT) $(INC) $^ -o $(NAME)

.PHONY : all clean fclean re bonus
