NAME = megaphone
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra

SRC = megaphone.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	rm -rf $(NAME)

