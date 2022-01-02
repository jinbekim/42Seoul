NAME = Bureaucrat
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
RM = rm -rf
SRC = main.cpp Bureaucrat.cpp
INC = -I./
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $?

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(INC) $? -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
