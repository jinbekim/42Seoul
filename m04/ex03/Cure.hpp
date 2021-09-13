#ifndef Cure_HPP
# define Cure_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	private:
	public:
		Cure(/* args*/);
		Cure(const Cure &ref);
		virtual ~Cure();
		Cure& operator=(const Cure &ref);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
