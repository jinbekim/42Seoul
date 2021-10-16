#include "Zombie.hpp"

void	Zombie::SetNameType(std::string &name, std::string &type){
	this->name = name;
	this->type = type;
}

Zombie::Zombie(){}

Zombie::Zombie(std::string &name, std::string &type):name(name), type(type){}

Zombie::~Zombie(){
	std::cout << "Greeeegggghhhh....." << std::endl;
}

void	Zombie::announce(){
	std::cout << "<" << name << "(" << type << ")>" << " Braiiiiiiinnnssss..." << std::endl;
}
