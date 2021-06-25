#include "phonebook.hpp"

phonebook::phonebook(const std::string value[10]){

}

void	phonebook::show_index(void)
{
	for(int j = 0; j < 3; j++){
		std::cout << " | ";
		std::cout << std::setw(10) << info_value[j];
	}
}

void	phonebook::show_info(void)
{
	for(int i = 0; i < 11; i++){
		std::cout.width(17);
		std::cout << info_key[i] << ": " << info_value[i] << std::endl;
	}
}

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
	for(int i = 0; i < 11; i++){
		std::cout << "what's your" << tmp.info_key[i] << std::endl;
		std::cin >> tmp.info_value[i];
	}
	tmp.filled = 1;
}

static void	search_func(phonebook (*data)[8])
{
	int	i = 0;

	while (i < 8 && (*data)[i].filled){
		std::cout << i;
		(*data)[i].show_index();
		std::cout << std::endl;
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
		// std::getline(std::cin, CMD);
		std::cin >> CMD;
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
