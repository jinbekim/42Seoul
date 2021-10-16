#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
}

Ice::Ice(const Ice &ref):AMateria("ice")
{
	*this = ref;
}

Ice::~Ice()
{
}

Ice& Ice::operator=(const Ice &ref)
{
	this->_xp = ref._xp;
	return (*this);
}

AMateria* Ice::clone() const
{
	Ice *cpy = new Ice(*this);
	return (cpy);
}

void Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout<< "* shoots an ice bolt at " <<
	target.getName() << " *"<< std::endl;
}
