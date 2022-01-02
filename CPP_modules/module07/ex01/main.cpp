#include <string>
#include <iostream>
#include "iter.hpp"

int main()
{
	int	intArray[5] = {1,2,3,4,5};
	double doubleArray[5] = {1.2, 2.3, 3.4, 4.5, 5.6};
	std::string stringArray[5] = {"hi", "bye", "annyoung", "good", "else"};


	iter(intArray, 5, display);
	std::cout << std::endl;
	iter(doubleArray, 5, display);
	std::cout << std::endl;
	iter(stringArray, 5, display);
	std::cout << std::endl;

	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can’t write int[] tab. Wouldn’t that make more sense?
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );

	return 0;
}
