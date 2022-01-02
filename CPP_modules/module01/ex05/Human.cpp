#include "Human.hpp"

Human::Human():brain("brain")
{
}

std::string	Human::identify() const
{
	return (this->brain.identify());
}

const Brain	&Human::getBrain() const
{
	return (brain);
}
