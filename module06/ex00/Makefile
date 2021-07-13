NAME = convert
GXX = clang++
GXXFLAGS = -Wall -Werror -Wextra
RM = rm -rf
SRC = convertor.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(GXX) $(GXXFLAGS) -c $?

all : $(NAME)

$(NAME): $(OBJ)
	$(GXX) $(GXXFLAGS) -I. -o $@ $?

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
