NAME = replace

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -I.

SRC = ft_sed.cpp main.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $?

clean :
	rm -rf $(NAME)
