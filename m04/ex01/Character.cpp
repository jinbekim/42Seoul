#include "Character.hpp"

Character::Character(std::string const& name):Name(name)
{
	this->AP = 40;
	this->weapon = NULL;
}

Character::Character(const Character &ref)
{
	*this = ref;
}

Character::~Character()
{
}

Character& Character::operator=(const Character &ref)
{
	this->Name = ref.Name;
	this->AP = ref.AP;
	this->weapon = ref.weapon;
	return (*this);
}

void	Character::recoverAP()
{
	if (AP == 40)
		return ;
	this->AP += 10;
	if (this->AP > 40)
		this->AP = 40;
}

void	Character::equip(AWeapon* weapon)
{
	this->weapon = weapon;
}


void	Character::attack(Enemy *enemy)
{
	if (this->weapon == NULL || (int)this->AP < this->weapon->getAPCost())
		return ;
	std::cout<<
	this->Name << " attacks " << enemy->getType() <<
	" with a " << this->weapon->getName()
	<< std::endl;
	this->AP -= this->weapon->getAPCost();
	this->weapon->attack();
	enemy->takeDamage(this->weapon->getDamage());
	if (enemy->getHP() <= 0)
		delete enemy;
}

std::string const& Character::getName() const
{
	return (this->Name);
}

std::string Character::getWeaponName() const
{
	if (this->weapon == NULL)
		return ("");
	return (this->weapon->getName());
}
unsigned int const& Character::getAP() const
{
	return (this->AP);
}
std::ostream&	operator<<(std::ostream& os, Character& character)
{
	os<<
	character.getName() << " has " << character.getAP() << " AP and ";
	if (character.getWeaponName() == "")
		os << "is unaramed" << std::endl;
	else
		os << " wields a " << character.getWeaponName() << std::endl;
	return (os);
}
