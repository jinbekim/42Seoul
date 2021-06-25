#ifndef PHONE
# define PHONE

# include <iostream>
# include <iomanip>
# include <string>

class	phonebook{
	public :
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	login;
		std::string	postal_address;
		std::string	email;
		std::string	phone_num;
		std::string	birthday_date;
		std::string	favorite_meal;
		std::string	underwear_color;
		std::string	darkest_secret;
		bool	filled;
		void	show_index(int i);
		void	show_info();
		// phonebook();
		// ~phonebook();
};

void	phonebook::show_index(int i)
{
	std::cout << std::setw(10) << i << "|";
	std::cout << std::setw(10) << first_name << "|";
	std::cout << std::setw(10) << last_name << "|";
	std::cout << std::setw(10) << nick_name << std::endl;
}
void	phonebook::show_info()
{
	std::cout << "first_name :" << first_name << std::endl;
	std::cout << "last_name :" << last_name << std::endl;
	std::cout << "nick_name :" << nick_name << std::endl;
	std::cout << "login :" << login << std::endl;
	std::cout << "postal_address :" << postal_address << std::endl;
	std::cout << "email :" << email << std::endl;
	std::cout << "phone_num :" << phone_num << std::endl;
	std::cout << "birthday_date :" << birthday_date << std::endl;
	std::cout << "favorite_meal :" << favorite_meal << std::endl;
	std::cout << "underwear_color :" << underwear_color << std::endl;
	std::cout << "darkest_secret :" << darkest_secret << std::endl;
}
#endif
