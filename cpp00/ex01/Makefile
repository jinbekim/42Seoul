NAME = phonebook
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
INC = -I./phonebook.hpp
SRC = phonebook.cpp main.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

clean :
	rm -rf $(NAME)

re : clean all

