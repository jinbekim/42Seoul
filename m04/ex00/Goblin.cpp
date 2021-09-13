#include "Goblin.hpp"

Goblin::Goblin(const std::string& name):Victim(name)
{
	std::cout<<
	"날이 좋아서 ... 태어남."
	<< std::endl;
}

Goblin::Goblin(const Goblin &ref):Victim(ref.name)
{
	*this = ref;
	std::cout<<
	"날이 좋아서 ... 태어남."
	<< std::endl;
}

Goblin::~Goblin()
{
	std::cout<<
	"모든 날이 좋았다. 죽음."
	<< std::endl;
}

Goblin& Goblin::operator=(const Goblin &ref)
{
	this->name = ref.name;
	return (*this);
}

void	Goblin::getPolymorphed() const
{
	std::cout<<
	this->get_name() << " Grrrrr.r......"
	<< std::endl;
}

void	Goblin::print_intro(void) const
{
	std::cout<<
	"나는 " << this->name << " 지은탁을 좋아함."
	<< std::endl;
}


std::ostream&	operator<<(std::ostream& os, const Goblin &goblin)
{
	os << "I'm " << goblin.get_name() << " and I like otters!\n";
	return (os);
}
