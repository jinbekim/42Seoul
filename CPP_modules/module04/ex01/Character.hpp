#ifndef Character_HPP
# define Character_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	private:
		std::string 	Name;
		unsigned int	AP;
		AWeapon*		weapon;
	public:
		Character(std::string const & name);
		Character(const Character &ref);
		~Character();
		Character& operator=(const Character &ref);

		void	recoverAP();
		void	equip(AWeapon*);
		void	attack(Enemy*);
		std::string const& getName() const;
		std::string getWeaponName() const;
		unsigned int const& getAP() const;
};

std::ostream&	operator<<(std::ostream& os, Character& character);
#endif
