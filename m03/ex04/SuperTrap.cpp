# include "SuperTrap.hpp"

SuperTrap::SuperTrap(const std::string &name): NinjaTrap(name), FlagTrap(name)
{
	this->Hit_points = this->FlagTrap::Hit_points;
	this->Max_hit_points = this->FlagTrap::Max_hit_points;
	this->Energy_points = this->NinjaTrap::Energy_points;
	this->Max_energy_points = this->NinjaTrap::Max_energy_points;
	this->Level = 1;
	this->Name = name;
	this->Melee_attack_damage = this->NinjaTrap::Melee_attack_damage;
	this->Ranged_attack_damage = this->FlagTrap::Ranged_attack_damage;
	this->Armor_damage_reduction = this->FlagTrap::Armor_damage_reduction;
}

SuperTrap::SuperTrap(const SuperTrap &ref): NinjaTrap(ref.Name), FlagTrap(ref.Name)
{
	ClapTrap::copy(ref);
}

SuperTrap::~SuperTrap()
{
	std::cout << "# SuperTrap is destroyed!!" << std::endl;
}

SuperTrap& SuperTrap::operator=(const SuperTrap &ref)
{
	ClapTrap::copy(ref);
	return (*this);
}

void	SuperTrap::meleeAttack(std::string const & target){
	FlagTrap::meleeAttack(target);
}
void	SuperTrap::rangedAttack(std::string const & target){
	NinjaTrap::rangedAttack(target);
}
