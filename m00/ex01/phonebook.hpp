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
		std::string info_value[11];
	public :
		bool		filled;
		void		set_value(int i, std::string value);
		std::string	get_value(int i);
		std::string show_key(int i);
		void		show_index();
		void		show_info();
		// phonebook();
		// ~phonebook();
};

#endif
