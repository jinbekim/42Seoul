#include "Victim.hpp"

Victim::Victim(const std::string& name): name(name)
{
	std::cout << "some random victim called "
	<< this->name << " just appeared!"<< std::endl;
}

Victim::Victim(const Victim &ref):name(ref.name)
{
	std::cout << "some random victim called "
	<< this->name << " just appeared!"<< std::endl;
}

Victim::~Victim()
{
	std::cout<<
	"Victim " << this->name << " just died for no apparent reason!"
	<< std::endl;
}

Victim& Victim::operator=(const Victim &ref)
{
	this->name = ref.name;
	return (*this);
}

const std::string &Victim::get_name(void) const
{
	return (this->name);
}


void	Victim::print_intro(void) const
{
	std::cout<<
	"I'm " << this->get_name() << " and I like otters!"
	<< std::endl;
}

void	Victim::getPolymorphed() const
{
	std::cout<<
	this->get_name() << " has been turned into a cute little sheep!"
	<< std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Victim &victim)
{
	os << "I'm " << victim.get_name() << " and I like otters!\n";
	return (os);
}
