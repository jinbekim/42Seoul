#ifndef AMateria_HPP
# define AMateria_HPP

# include <iostream>
# include <string>
class	AMateria;
# include "ICharacter.hpp"

class AMateria
{
	protected:
		AMateria();

		std::string	_type;
		unsigned int _xp;
	public:
		AMateria(const std::string & type);
		AMateria(const AMateria &ref);
		virtual ~AMateria();
		AMateria& operator=(const AMateria &ref);

		std::string const & getType() const;
		unsigned int getXP() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
