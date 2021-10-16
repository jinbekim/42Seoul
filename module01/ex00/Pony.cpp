#include "Pony.hpp"

//생성자
Pony::Pony(const std::string& name):name_(name)
{
	std::cout << this->name_ << " Constructed!" << std::endl;
}
//소멸자
Pony::~Pony(){
	std::cout << this->name_ << " Destructed!" << std::endl;
}

void	Pony::intro(void){
	std::cout << "My name is " << this->name_ << std::endl;
}

void	Pony::address(void){
	std::cout << this <<std::endl;
}
