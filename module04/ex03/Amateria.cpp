#include "AMateria.hpp"

AMateria::AMateria(const std::string & type):_type(type), _xp(0)
{
}

AMateria::AMateria(const AMateria &ref):_type(ref._type), _xp(ref._xp)
{
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria &ref)
{
	this->_xp = ref._xp;
	this->_type = ref._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}
unsigned int AMateria::getXP() const
{
	return (this->_xp);
}
void AMateria::use(ICharacter& target)
{
	(void)target;
	this->_xp += 10;
}
