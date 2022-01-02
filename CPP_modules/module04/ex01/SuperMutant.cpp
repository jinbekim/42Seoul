#include "SuperMutant.hpp"

SuperMutant::SuperMutant():Enemy(170, "Super Mutant")
{
	std::cout<<"Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &ref):Enemy(ref)
{
	std::cout<< "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout<<"Aaargh..."<< std::endl;
}

SuperMutant& SuperMutant::operator=(const SuperMutant &ref)
{
	Enemy::copy(ref);
	return (*this);
}

void SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	if (damage < 0 || this->HP <= 0)
		return ;
	this->HP -= damage;
	if (this->HP < 0)
		this->HP = 0;
}
