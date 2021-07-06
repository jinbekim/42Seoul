#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
:name(name), title(title)
{
	std::cout<< this->name << ", " <<this->title << ", is born!" << std::endl;
}
Sorcerer::Sorcerer(const Sorcerer &ref)
{
	this->name = ref.name;
	this->title = ref.title;
	std::cout<< this->name << ", " <<this->title << ", is born!" << std::endl;
}
Sorcerer::~Sorcerer()
{
	std::cout<< this->name << ", " <<this->title << ", is dead. Consequences will never be the same!" << std::endl;
}
Sorcerer& Sorcerer::operator=(const Sorcerer &ref)
{
	this->name = ref.name;
	this->title = ref.title;
	return (*this);
}

const std::string& Sorcerer::get_name() const
{
	return (this->name);
}
const std::string& Sorcerer::get_title() const
{
	return (this->title);
}
void	Sorcerer::print_intro(void) const
{
	std::cout <<
	"I am " + this->get_name() + ", " + this->get_title() + ", and i like ponies!"
	 << std::endl;
}
std::ostream&	operator<<(std::ostream& os, const Sorcerer &sorcerer)
{
	os << "I am " << sorcerer.get_name() << ", " + sorcerer.get_title() << ", and i like ponies!\n";
	return (os);
}

void	Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

void	Sorcerer::polymorph(Peon const &peon) const
{
	peon.getPolymorphed();
}

void	Sorcerer::polymorph(Goblin const &goblin) const
{
	goblin.getPolymorphed();
}
