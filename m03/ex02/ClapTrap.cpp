#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name):Name(name)
{
	std::cout << "generated ClapTrap!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	ClapTrap::copy(ref);
}

void	ClapTrap::copy(const ClapTrap &ref){
	this->Level = ref.Level;
	this->Hit_points = ref.Hit_points;
	this->Energy_points = ref.Energy_points;
	this->Max_hit_points = ref.Max_hit_points;
	this->Max_energy_points = ref.Max_energy_points;
	this->Melee_attack_damage = ref.Melee_attack_damage;
	this->Ranged_attack_damage = ref.Ranged_attack_damage;
	this->Armor_damage_reduction = ref.Armor_damage_reduction;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap distroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
{
	ClapTrap::copy(ref);
	return (*this);
}

void	ClapTrap::rangedAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "range"\
	<<", causing <" << Ranged_attack_damage\
	<<"> points of damage!\n# rangedAttack!!!"\
	<< std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "melee"\
	<<", causing <" << Melee_attack_damage\
	<<"> points of damage!\n# meleeAttack!!!"\
	<< std::endl;
}

int ClapTrap::cal_damage(unsigned int amount) const {
	return (\
	(const int)(amount - Armor_damage_reduction) > Hit_points ?\
	Hit_points : amount - Armor_damage_reduction);
}

void	ClapTrap::takeDamage(unsigned int amount){
	int	calculated_amount = cal_damage(amount);

	Hit_points -= calculated_amount;
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> is attacked <" << amount << "> power of damege. lose total <"\
	<< calculated_amount\
	<< "> Hit_points.\n"\
	<< "# Now you have <" << Hit_points << "> Hit_points."
	<< std::endl;
}

int ClapTrap::cal_repair(unsigned int amount) const {
	return (\
	(const int)(Hit_points + amount) > Max_hit_points ?\
	Max_hit_points - Hit_points : amount);
}

void	ClapTrap::beRepaired(unsigned int amount){
	int	calculated_amount = cal_repair(amount);

	Hit_points += calculated_amount;
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> is repaired <" << calculated_amount\
	<< "> of Hit_points.\n# Now you have <" << Hit_points\
	<< "> Hit_points."\
	<< std::endl;
}
