#include "ScavTrap.hpp"

std::string	ScavTrap::challenges[5] = {
	"Drink soju 1000 btl",
	"Piscine Ruby on Rails",
	"Piscine PHP",
	"ft_printf bonus",
	"miniRT bonus"
};

ScavTrap::ScavTrap(const std::string &name):
Name(name)
{
	Hit_points = 100;
	Energy_points = 100;
	Level = 1;
	Max_hit_points = 50;
	Max_energy_points = 50;
	Melee_attack_damage = 20;
	Ranged_attack_damage = 15;
	Armor_damage_reduction = 3;
}

ScavTrap::ScavTrap(const ScavTrap &ref):
Max_hit_points(100),\
Max_energy_points(50),\
Melee_attack_damage(20),\
Ranged_attack_damage(15),\
Armor_damage_reduction(3)
{
	*this = ref;
}

ScavTrap::~ScavTrap()
{
	std::cout << "# FR4G-TP<" <<this->Name << "> is terminated!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ref)
{
	this->Name = ref.Name;
	this->Level = ref.Level;
	this->Hit_points = ref.Hit_points;
	this->Energy_points = ref.Energy_points;
	return (*this);
}

void	ScavTrap::rangedAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "range"\
	<<", causing <" << Ranged_attack_damage\
	<<"> points of damage!\n# rangedAttack!!!"\
	<< std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "melee"\
	<<", causing <" << Melee_attack_damage\
	<<"> points of damage!\n# meleeAttack!!!"\
	<< std::endl;
}

int ScavTrap::cal_damage(unsigned int amount) const {
	return (\
	(const int)(amount - Armor_damage_reduction) > Hit_points ?\
	Hit_points : amount - Armor_damage_reduction);
}

void	ScavTrap::takeDamage(unsigned int amount){
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

int ScavTrap::cal_repair(unsigned int amount) const {
	return (\
	(const int)(Hit_points + amount) > Max_hit_points ?\
	Max_hit_points - Hit_points : amount);
}

void	ScavTrap::beRepaired(unsigned int amount){
	int	calculated_amount = cal_repair(amount);

	Hit_points += calculated_amount;
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> is repaired <" << calculated_amount\
	<< "> of Hit_points.\n# Now you have <" << Hit_points\
	<< "> Hit_points."\
	<< std::endl;
}

void	ScavTrap::challengeNewcomer(void){
	std::cout\
	<<"FR4G-TP <" << Name\
	<< "> " << ScavTrap::challenges[rand() % 5] << std::endl;
}
