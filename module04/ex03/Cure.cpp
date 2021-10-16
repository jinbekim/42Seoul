#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
}

Cure::Cure(const Cure &ref):AMateria("cure")
{
	*this = ref;
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure &ref)
{
	this->_xp = ref._xp;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}
void Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout<< "* heals " <<
	target.getName() << "'s wounds *"<< std::endl;
}

