#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(const std::string &Name):ClapTrap(Name)
{
	std::cout << "# generated NinjaTrap!!" << std::endl;
	Hit_points = 60;
	Energy_points = 120;
	Level = 1;
	Max_hit_points = 60;
	Max_energy_points = 120;
	Melee_attack_damage = 60;
	Ranged_attack_damage = 5;
	Armor_damage_reduction = 0;
}

NinjaTrap::NinjaTrap(const NinjaTrap &ref):ClapTrap()
{
	ClapTrap::copy(ref);
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "# NinjaTrap distroyed" << std::endl;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap &ref)
{
	ClapTrap::copy(ref);
	return (*this);
}

void	NinjaTrap::ninjaShoebox(ClapTrap& target){
	if (this->Energy_points < 20){
		std::cout << "# You out of Energy!" << std::endl;
		return ;
	}
	this->Energy_points -= 20;
	int	damage = rand() % 10 + 10;
	std::cout << "# You slapped " << target.getName() << "\n"
	<< this->getName() << "slap slap slapp!!" << std::endl;
	target.takeDamage(damage);
}
void	NinjaTrap::ninjaShoebox(FlagTrap& target){
	if (this->Energy_points < 20){
		std::cout << "# You out of Energy!" << std::endl;
		return ;
	}
	this->Energy_points -= 20;
	int	damage = rand() % 10 + 10;
	std::cout << "# You throw a arrow to " << target.getName() << "\n"
	<< this->getName() << ": twang twang twang !!!" << std::endl;
	target.takeDamage(damage);
}
void	NinjaTrap::ninjaShoebox(ScavTrap& target){
	if (this->Energy_points < 20){
		std::cout << "# You out of Energy!" << std::endl;
		return ;
	}
	this->Energy_points -= 20;
	int	damage = rand() % 10 + 10;
	std::cout << "# You provoke " << target.getName() << "\n"
	<< this->getName() << ": Get your ass over HERE!!" << std::endl;
	target.takeDamage(damage);
}
void	NinjaTrap::ninjaShoebox(NinjaTrap& target){
	if (this->Energy_points < 20){
		std::cout << "# You out of Energy!" << std::endl;
		return ;
	}
	this->Energy_points -= 20;
	int	damage = rand() % 10 + 10;
	std::cout << "# You shot dart to " << target.getName() << "\n"
	<< target.getName() << ": aaaaahaaaaahaaaaah!!" << std::endl;
	target.takeDamage(damage);
}

void	NinjaTrap::rangedAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "range"\
	<<", causing <" << Ranged_attack_damage\
	<<"> points of damage!\n# NinjaTrap:: rangedAttack!!!"\
	<< std::endl;
}

void	NinjaTrap::meleeAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "melee"\
	<<", causing <" << Melee_attack_damage\
	<<"> points of damage!\n# NinjaTrap:: meleeAttack!!!"\
	<< std::endl;
}
