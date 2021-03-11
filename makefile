# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 02:51:58 by jinbekim          #+#    #+#              #
#    Updated: 2021/03/11 16:09:43 by jinbekim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d.out
SRC = main.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -g3 -fsanitize=address -framework AppKit -framework OpenGL -lz -L. -lmlx $^ -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
