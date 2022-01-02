NAME = 28B
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
RM = rm -rf
INC = -I./
SRC = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp\
	RobotomyRequestForm.cpp ShrubberyCreationForm.cpp\
	Intern.cpp
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
