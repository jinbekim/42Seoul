#include "phonebook.hpp"

static void	add_func(phonebook (*data)[8])
{
	int	i = 0;
	phonebook tmp;
	std::string greeting_msg = "Please enter in the following order.";

	while (i < 8 && (*data)[i].filled)
		i++;
	if (i == 8)
		tmp = (*data)[0];
	else
		tmp = (*data)[i];
	std::cout << "what's your first and last name?" << std::endl;
	std::cin >> tmp.first_name >> tmp.last_name;
	std::cout << "what's your nick name?" << std::endl;
	std::cin >> tmp.nick_name;
	std::cout << "what's your login?" << std::endl;
	std::cin >> tmp.login;
	std::cout << "what's your phone number?" << std::endl;
	std::cin >> tmp.phone_num;
	std::cout << "what's your birthday_date?" << std::endl;
	std::cin >> tmp.birthday_date;
	std::cout << "what's your favorite_meal?" << std::endl;
	std::cin >> tmp.favorite_meal;
	std::cout << "what's your underwear_color?" << std::endl;
	std::cin >> tmp.underwear_color;
	std::cout << "what's your darkest_secret?" << std::endl;
	std::cin >> tmp.darkest_secret;
	tmp.filled = 1;
	std::cout << "your data saved succesfully" << std::endl;
	tmp.show_info();
}

static void	search_func(phonebook (*data)[8])
{
	int	i = 0;

	while (i < 8 && (*data)[i].filled)
	{

		i++;
	}
}

int	main(void)
{
	std::string	CMD;
	std::string greeting_msg = "Please enter command. ADD, SEARCH or EXIT";
	std::string goodbye_msg = "Good bye!, you will lose everything.  :(";
	phonebook	data[8];

	while (CMD.compare("EXIT") && CMD != "exit")
	{
		std::cout << greeting_msg << std::endl;
		std::getline(std::cin, CMD);
		if (!CMD.compare("ADD") || CMD == "add")
			add_func(&data);
		else if (!CMD.compare("SEARCH") || !CMD.compare("search"))
			search_func(&data);
		else
			continue ;
	}
	std::cout << goodbye_msg << std::endl;
	return (0);
}
