#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout<< "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &ref)
{
	std::cout<< "* teleports from space *" << std::endl;
	*this = ref;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout<< "I'll be back..." << std::endl;
}

AssaultTerminator& AssaultTerminator::operator=(const AssaultTerminator &ref)
{
	(void)ref;
	return (*this);
}

ISpaceMarine* AssaultTerminator::clone() const
{
	return (new AssaultTerminator());
}

void AssaultTerminator::battleCry() const
{
	std::cout<< "This code is unclean. PURIFY IT!" << std::endl;
}
void AssaultTerminator::rangedAttack() const
{
	std::cout<< "* does nothing  *" << std::endl;
}
void AssaultTerminator::meleeAttack() const
{
	std::cout<< "* attacks with chainfists *" << std::endl;
}
