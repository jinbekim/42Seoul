#include "convertor.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return (0);
	convertor hi(argv[1]);
	try
	{
		std::cout << "char: " << static_cast<char>(hi) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout<< "int: " << static_cast<int>(hi) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		float tmp = static_cast<float>(hi);
		std::cout << "float: ";
		if (tmp - static_cast<int>(hi) == 0)
			std::cout << std::fixed <<std::setprecision(1) << tmp << "f" << std::endl;
		else
			std::cout << tmp  << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout<< "double: " << static_cast<double>(hi)<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
