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

static int	find_index(phonebook (&data)[8]){
	int	i = 0;

	while (i < 8 && data[i].filled)
		i++;
	if (i == 8)
	{
		for (int i = 0; i < 7; i++){
			data[i] = data[i + 1];
		}
		i = 7;
	}
	return (i);
}

static void	add_func(phonebook (&data)[8])
{
	std::string	tmp_value;
	int	i, j;

	j = find_index(data);
	i = -1;
	while (++i < 11 && !std::cin.eof()){
		std::cout << "# what's your " << data[j].show_key(i) << "?\n> ";
		getline(std::cin, tmp_value);
		data[j].set_value(i, tmp_value);
	}
	data[j].filled = 1;
	std::cout << std::endl;
}

static void	show_title(){
	std::cout << "|" << center_align(10, "index") << "|";
	std::cout << center_align(10, "first name") << "|";
	std::cout << center_align(10, "last name") << "|";
	std::cout << center_align(10, "nick name") << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

static void	show_index(phonebook (&data)[8]){
	int	i = 0;

	while (i < 8 && data[i].filled){
		std::cout << "|" << std::setw(10) << i << "|";
		data[i].show_index();
		std::cout << std::endl;
		i++;
	}
}

static void	search_func(phonebook (&data)[8])
{
	int	i = 0;

	if (data[0].filled == 0)
	{
		std::cout << "# Book is empty, add first!" << std::endl;
		return ;
	}
	show_title();
	show_index(data);
	std::cout << "# Input index num on the list\n> ";
	while (!std::cin.eof())
	{
		std::cin >> i;
		if (!std::cin.fail() && (i >=0 && i <= 7) && data[i].filled)
			break ;
		std::cout << "# please select on the list in integer!" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	if (!std::cin.eof()){
		std::cin.ignore();
		data[i].show_info();
	}
}

int	main(void)
{
	std::string	CMD;
	std::string greeting_msg = "# Please enter command. ADD, SEARCH or EXIT (:";
	std::string goodbye_msg = "# Good bye!, you will lose everything. :(";
	phonebook	data[8];

	while (!std::cin.eof())
	{
		std::cout << greeting_msg << "\n> ";
		getline(std::cin, CMD);
		if (!CMD.compare("EXIT") || CMD == "exit")
			break ;
		else if (!CMD.compare("ADD") || CMD == "add")
			add_func(data);
		else if (!CMD.compare("SEARCH") || !CMD.compare("search"))
			search_func(data);
		else
			continue ;
	}
	std::cout << '\n' << goodbye_msg << std::endl;
	return (0);
}
