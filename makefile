# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 02:51:58 by jinbekim          #+#    #+#              #
#    Updated: 2021/02/27 03:15:26 by jinbekim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d.out
SRC = test.c
OBJ = test.o

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -framework AppKit -framework OpenGL -lz -L. -lmlx -Iget_next_line $^ -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus