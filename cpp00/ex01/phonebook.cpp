#include "phonebook.hpp"

static void	add_func(void)
{
	std::string greeting_msg = "Please enter in the following order.";
	std::string input_list = "first name, last name, nickname, \
	login, postal address, email address, phone number, birthday date, favorite \
	meal, underwear color and darkest secret";
	std::cout << input_list << std::endl;

}

static void	search_func(void)
{
	// index, first name, last name and nickname.

}

int	main(void)
{
	std::string	CMD;
	std::string greeting_msg = "Please enter command. ADD, SEARCH or EXIT";
	std::string goodbye_msg = "Good bye!, you will lose everything.  :(";

	while (CMD.compare("EXIT") || CMD.compare("exit"))
	{
		std::cout << greeting_msg << std::endl;
		std::getline(std::cin, CMD);
		if (!CMD.compare("ADD") || CMD == "add")
			add_func();
		else if (!CMD.compare("SEARCH") || !CMD.compare("search"))
			search_func();
		else
			continue ;
	}
	std::cout << goodbye_msg << std::endl;
	return (0);
}
