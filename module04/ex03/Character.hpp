#ifndef Character_HPP
# define Character_HPP

# include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria*	inventory[4];
	public:
		Character(const std::string & name);
		Character(const Character &ref);
		virtual ~Character();
		Character& operator=(const Character &ref);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
