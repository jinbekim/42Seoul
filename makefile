# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 02:51:58 by jinbekim          #+#    #+#              #
#    Updated: 2021/03/25 04:45:33 by jinbekim         ###   ########.fr        #
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
	# key_control.c \
	# game_close.c \
	# mouse_move.c \
	# wall.c \
	# stripe.c \
	# floor_ceil.c \
	# sprite.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC)
	$(MAKE) -C ./libft
	# $(CC) -g3 -fsanitize=address $(MLX) $(LIBFT) $(INC) $^ -o $(NAME)
	$(CC) -g3 -fsanitize=address -framework AppKit -framework OpenGL -lz $(MLX) $(LIBFT) $(INC) $^ -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
