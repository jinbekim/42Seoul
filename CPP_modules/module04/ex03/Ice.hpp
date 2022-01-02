#ifndef Ice_HPP
# define Ice_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	private:
	public:
		Ice(/* args*/);
		Ice(const Ice &ref);
		virtual ~Ice();
		Ice& operator=(const Ice &ref);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
