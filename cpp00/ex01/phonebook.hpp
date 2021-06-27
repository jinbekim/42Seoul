#ifndef PHONE_HPP
# define PHONE_HPP

# include <iostream>
# include <iomanip>
# include <string>

enum e_key{
	first_name,
	last_name,
	nick_name,
	login,
	postal_address,
	email,
	phone_num,
	birthday_date,
	favorite_meal,
	underwear_color,
	darkest_secret,
};
class	phonebook{
	private:

	public :
		std::string	info_key[11];
		std::string info_value[11];
		bool		filled;
		void		show_index();
		void		show_info();
		phonebook();
		// ~phonebook();
};

#endif
