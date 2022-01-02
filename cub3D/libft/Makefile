# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 18:47:30 by jinbekim          #+#    #+#              #
#    Updated: 2021/04/02 20:54:42 by jinbekim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I./includes
AR = ar rcs

FUNC = ft_atoi \
	ft_isalpha \
	ft_isprint \
	ft_toupper \
	ft_tolower \
	ft_isascii \
	ft_isalnum \
	ft_isdigit \
	ft_strncmp \
	ft_memcmp \
	ft_bzero \
	ft_memset \
	ft_memchr \
	ft_memcpy \
	ft_memmove \
	ft_memccpy \
	ft_strchr \
	ft_strrchr \
	ft_strnstr \
	ft_strlen \
	ft_strlcpy \
	ft_strlcat \
	ft_calloc \
	ft_strdup \
	ft_strjoin \
	ft_strtrim \
	ft_itoa \
	ft_strmapi \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_substr \
	get_next_line \
	get_next_line_utils \
	ft_lstnew \
	ft_lstadd_front \
	ft_lstsize \
	ft_lstlast \
	ft_lstadd_back \
	ft_lstdelone \
	ft_lstclear \
	ft_lstiter \
	ft_lstmap

OBJS = $(addprefix objs/, $(addsuffix .o, $(FUNC)))
SRCS = $(addprefix srcs/, $(addsuffix .c, $(FUNC)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $?

objs/%.o : srcs/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $?

.PHONY : clean fclean re bonus

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : clean all
