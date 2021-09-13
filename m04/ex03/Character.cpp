#include "Character.hpp"

Character::Character(const std::string &name):_name(name)
{
	for(int i = 0; i < 4; ++i)
		this->inventory[i] = nullptr;
}

Character::Character(const Character &ref)
{
	*this = ref;
}

Character::~Character()
{
	for(int i = 0 ; i < 4 ; ++i){
		if (this->inventory[i] != nullptr){
			delete this->inventory[i];
			this->inventory[i] = nullptr;
		}
	}
}

Character& Character::operator=(const Character &ref)
{
	for (int i = 0 ; i < 4 ; ++i){
		if (this->inventory[i] != nullptr)
		{
			delete this->inventory[i];
			this->inventory[i] = nullptr;
		}
	}
	this->_name = ref._name;
	for (int i = 0 ; i < 4 ; ++i){
		if (ref.inventory[i] != nullptr){
			this->inventory[i] = ref.inventory[i]->clone();
		}else{
			this->inventory[i] = ref.inventory[i];
		}
	}
	return (*this);
}
std::string const & Character::getName() const
{
	return (this->_name);
}
void Character::equip(AMateria* m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4 ; ++i){
		if (this->inventory[i] == m)
			return ;
		else if (this->inventory[i] == nullptr){
			this->inventory[i] = m;
			break ;
		}
	}
}
void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
		return ;
	this->inventory[idx] = nullptr;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->inventory[idx] == nullptr)
		return ;
	this->inventory[idx]->use(target);
}
