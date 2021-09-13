#include "Peon.hpp"

Peon::Peon(const std::string& name): Victim(name)
{
	std::cout<<
	"Zog zog."
	<< std::endl;
}

Peon::Peon(const Peon &ref): Victim(ref.name)
{
	std::cout<<
	"Zog zog."
	<< std::endl;
}

Peon::~Peon()
{
	std::cout<<
	"Bleuark..."
	<< std::endl;
}

Peon& Peon::operator=(const Peon &ref)
{
	this->name = ref.name;
	return (*this);
}

void	Peon::getPolymorphed() const
{
	std::cout<<
	this->get_name() << " has been turned into a pink pony!"
	<< std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Peon &peon)
{
	os << "I'm " << peon.get_name() << " and I like otters!\n";
	return (os);
}
