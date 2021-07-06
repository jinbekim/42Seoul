#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string& name, int apcost, int damage)
: Name(name), APCost(apcost), Damage(damage)
{
}
AWeapon::AWeapon(const AWeapon &ref)
{
	AWeapon::copy(ref);
}
AWeapon::~AWeapon(){}
AWeapon& AWeapon::operator=(const AWeapon &ref)
{
	AWeapon::copy(ref);
	return (*this);
}
void	AWeapon::copy(const AWeapon& ref)
{
	this->Name = ref.Name;
	this->APCost = ref.APCost;
	this->Damage = ref.Damage;
}

const std::string& AWeapon::getName() const
{
	return (this->Name);
}
int AWeapon::getAPCost() const
{
	return (this->APCost);
}
int AWeapon::getDamage() const
{
	return (this->Damage);
}
