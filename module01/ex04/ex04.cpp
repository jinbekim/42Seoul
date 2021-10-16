#include <iostream>
#include <string>
#include <iomanip>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string *ptr = &brain;
	std::string &ref = brain;

	std::cout << std::setw(10) << std::left << "# origin" << ":" << brain << std::endl;
	std::cout << std::setw(10) << std::left << "# ptr" << ":" << *ptr << std::endl;
	std::cout << std::setw(10) << std::left << "# ref" <<  ":" <<ref << std::endl;
}
