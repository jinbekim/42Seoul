# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 02:51:58 by jinbekim          #+#    #+#              #
#    Updated: 2021/04/01 02:34:22 by jinbekim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3D
INC = -Iincludes/
MLX = -L./mlx -lmlx
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
	sprite2.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC)
	$(MAKE) -C ./libft
	$(CC) -O3 -g3 -fsanitize=address $(MLX) $(LIBFT) $(INC) $^ -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
