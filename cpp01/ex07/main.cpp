#include "ft_sed.hpp"

int main (int ac, const char **argv) {
	if (ac != 4)
	{
		std::cout << "error : Wrong num of argv!" << std::endl;
		return (1);
	}
	try{
		ft_sed::replace(argv[1], argv[2], argv[3]);
	}catch(const char *str){
		std::cerr << str << " is error" << std::endl;
	}catch(...){
		std::cerr << "something is wrong" << std::endl;
	}
	std::cout << "program end." << std::endl;
	return 0;
}
