#include "ScavTrap.hpp"

std::string	ScavTrap::challenges[5] = {
	"Drink soju 1000 btl",
	"Piscine Ruby on Rails",
	"Piscine PHP",
	"ft_printf bonus",
	"miniRT bonus"
};

ScavTrap::ScavTrap(const std::string &name):ClapTrap(name)
{
	std::cout << "generated ScavTrap!!" << std::endl;
	Level = 1;
	Hit_points = 100;
	Energy_points = 50;
	Max_hit_points = 100;
	Max_energy_points = 50;
	Melee_attack_damage = 20;
	Ranged_attack_damage = 15;
	Armor_damage_reduction = 3;
}

ScavTrap::ScavTrap(const ScavTrap &ref):ClapTrap(ref.Name)
{
	ClapTrap::copy(ref);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap distroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ref)
{
	ClapTrap::copy(ref);
	return (*this);
}

void	ScavTrap::challengeNewcomer(void){
	std::cout\
	<<"FR4G-TP <" << Name\
	<< "> " << ScavTrap::challenges[rand() % 5] << std::endl;
}
