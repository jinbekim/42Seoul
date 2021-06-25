NAME = phonebook
CC = clang++
CPPFLAGS = -Wall -Werror -Wextra
INC = -I./phonebook.hpp
SRC = phonebook.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CPPFLAGS) $(INC) $^ -o $@

clean :
	rm -rf $(NAME)

