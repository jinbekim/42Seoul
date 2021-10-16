#ifndef Weapon_HPP
# define Weapon_HPP

# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(const std::string &name);
		const std::string &getType() const;
		void	setType(std::string type);
};

#endif
