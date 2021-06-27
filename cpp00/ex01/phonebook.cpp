#include "phonebook.hpp"

static std::string	center_align(int setw, const std::string& str){
	int	len = str.length();

	if (len >= 10)
		return (str);
	int	padding = setw - len;
	int	pad_left = padding / 2;
	int	pad_right = padding - pad_left;
	return (std::string(pad_left, ' ') + str + std::string(pad_right, ' '));
}

phonebook::phonebook(){
	info_key[first_name] = "first_name";
	info_key[last_name] = "last_name";
	info_key[nick_name] = "nick_name";
	info_key[login] = "login";
	info_key[postal_address] = "postal_address";
	info_key[email] = "email";
	info_key[phone_num] = "phone_num";
	info_key[birthday_date] = "birthday_date";
	info_key[favorite_meal] = "favorite_meal";
	info_key[underwear_color] = "underwear_color";
	info_key[darkest_secret] = "darkest_secret";
	filled = 0;
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
		std::cout << info_key[i] << ": " << info_value[i] << std::endl;
	}
}

static void	add_func(phonebook (*data)[8])
{
	int	i = 0;
	phonebook *tmp;

	while (i < 8 && (*data)[i].filled)
		i++;
	if (i == 8)
		tmp = &(*data)[0];
	else
		tmp = &(*data)[i];
	for(int i = 0; i < 11; i++){
		std::cout << "🤔what's your " << tmp->info_key[i] << "?" <<std::endl;
		std::cin >> tmp->info_value[i];
	}
	tmp->filled = 1;
}


static void	search_func(phonebook (*data)[8])
{
	int	i = 0;

	std::cout << "|" << center_align(10, "index") << "|";
	std::cout << center_align(10, "first name") << "|";
	std::cout << center_align(10, "last name") << "|";
	std::cout << center_align(10, "nick name") << "|" << std::endl;
	while (i < 8 && (*data)[i].filled){
		std::cout << "|" << std::setw(10) << i << "|";
		(*data)[i].show_index();
		std::cout << std::endl;
		i++;
	}
}

int	main(void)
{
	std::string	CMD;
	std::string greeting_msg = "😀🥳Please enter command. ADD, SEARCH or EXIT";
	std::string goodbye_msg = "Good bye!, you will lose everything. 🥲😿";
	phonebook	data[8];

	// enter만 입력할때 이유. 갱신되게 만들기.
	while (CMD.compare("EXIT") && CMD != "exit")
	{
		std::cout << greeting_msg << std::endl;
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
