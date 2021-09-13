#include "RadScorpion.hpp"

RadScorpion::RadScorpion():Enemy(80, "RadScorpion")
{
	std::cout<< "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &ref):Enemy(ref)
{
	std::cout<< "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout<<
	"* SPROTCH *"
	<< std::endl;
}

RadScorpion& RadScorpion::operator=(const RadScorpion &ref)
{
	Enemy::copy(ref);
	return (*this);
}

void	RadScorpion::takeDamage(int damage)
{
	if (damage < 0 || this->HP <= 0)
		return ;
	this->HP -= damage;
	if (this->HP < 0)
		this->HP = 0;
}
