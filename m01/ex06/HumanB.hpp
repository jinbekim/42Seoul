#ifndef HumanB_HPP
# define HumanB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		const std::string	name;
		Weapon				*weapon;
	public:
		HumanB(const std::string &name);
		void	setWeapon(Weapon &weapon);
		void	attack() const;
};

#endif
