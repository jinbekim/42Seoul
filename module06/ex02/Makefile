NAME = dynamicCast
GXX = clang++
GXXFLAGS = -Wall -Werror -Wextra
RM = rm -rf
SRC = Alpha.cpp Base.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(GXX) $(GXXFLAGS) -c $?

all : $(NAME)

$(NAME): $(OBJ)
	$(GXX) $(GXXFLAGS) -g3 -fsanitize=address -I. -o $@ $?

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
