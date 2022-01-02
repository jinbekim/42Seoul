#include "phonebook.hpp"

void	phonebook::set_value(int i, std::string value){
	info_value[i] = value;
}

std::string	phonebook::get_value(int i){
	return (info_value[i]);
}

std::string	phonebook::show_key(int i)
{
	static std::string	info_key[11]
	=
	{
		"FirstName",
		"LastName",
		"NickName",
		"Login",
		"PostalAddress",
		"Email",
		"PhoneNumber",
		"BDay",
		"FavoriteMeal",
		"UnderwearColor",
		"DarkestSecret"
	};
	return (info_key[i]);
}

void	phonebook::show_index(void)
{
	std::string	tmp;

	for(int j = 0; j < 3; j++){
		if (info_value[j].length() >= 10)
			std::cout << info_value[j].substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << info_value[j];
		std::cout << "|";
	}
}

void	phonebook::show_info(void)
{
	for(int i = 0; i < 11; i++){
		std::cout.width(17);
		std::cout << std::left << show_key(i) << ": " << get_value(i) << std::endl;
	}
}
