#ifndef HumanA_HPP
# define HumanA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		const std::string	name;
		const Weapon		&weapon;
	public:
		HumanA(const std::string &name, Weapon &weapon);
		void	attack() const;
};

#endif
