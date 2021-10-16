#include "Zombie.hpp"

Zombie::Zombie(std::string const &name, std::string const &type)
	:name(name), type(type)
{
}

Zombie::~Zombie(){
	std::cout << "Greeeegggghhhh....." << std::endl;
}

void	Zombie::announce(){
	std::cout << "<" << name << "(" << type << ")>" << " Braiiiiiiinnnssss..." << std::endl;
}
