#include <string>
#include <iostream>
#include "iter.hpp"

int main()
{
	int	intArray[5] = {1,2,3,4,5};
	double doubleArray[5] = {1.2, 2.3, 3.4, 4.5, 5.6};
	std::string stringArray[5] = {"hi", "bye", "annyoung", "good", "else"};


	iter(intArray, 5, print);
	std::cout << std::endl;
	iter(doubleArray, 5, print);
	std::cout << std::endl;
	iter(stringArray, 5, print);
	std::cout << std::endl;

	return 0;
}
