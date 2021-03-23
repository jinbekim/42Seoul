# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 02:51:58 by jinbekim          #+#    #+#              #
#    Updated: 2021/03/23 23:00:00 by jinbekim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3D
INC = -Iincludes/
MLX = -L./mlx_bata -lmlx
SRC = main.c \
	key_control.c \
	game_close.c \
	mouse_move.c \
	wall.c \
	stripe.c \
	floor_ceil.c \
	sprite.c \
	error_handling.c


all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -g3 -fsanitize=address $(MLX) $(INC) $^ -o $(NAME)
	# $(CC) -g3 -fsanitize=address -framework AppKit -framework OpenGL -lz -L. -lmlx $^ -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
