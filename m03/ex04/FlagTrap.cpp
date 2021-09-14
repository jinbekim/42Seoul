#include "FlagTrap.hpp"

std::string FlagTrap::skill[5] = {
	"fire_storm",
	"thunder_strom",
	"water_storm",
	"electric_storm",
	"tornado_storm"
};

FlagTrap::FlagTrap(const std::string &name):ClapTrap(name)
{
	std::cout << "# generated FlagTrap!!" << std::endl;
	Hit_points = 100;
	Energy_points = 100;
	Level = 1;
	Max_hit_points = 100;
	Max_energy_points = 100;
	Melee_attack_damage = 20;
	Ranged_attack_damage = 30;
	Armor_damage_reduction = 5;
}

FlagTrap::FlagTrap(const FlagTrap &ref):ClapTrap(ref.Name)
{
	ClapTrap::copy(ref);
}

FlagTrap::~FlagTrap()
{
	std::cout << "FlagTrap distroyed" << std::endl;
}

FlagTrap& FlagTrap::operator=(const FlagTrap &ref)
{
	ClapTrap::copy(ref);
	return (*this);
}


void		FlagTrap::cast_valuthnter(std::string const &target, int num){
	this->Energy_points -= 25;
	for (int i = 0; i < 3; ++i){
		std::cout << "casting...\n";
	}
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << skill[num]\
	<<", causing <" << 20 + num\
	<<"> points of damage!\n"\
	<<"You left <" << this->Energy_points << "/" << this->Max_energy_points\
	<<"> Energy_points"
	<< std::endl;
}

void	FlagTrap::vaulthunter_dot_exe(std::string const & target){
	std::random_device	rd;
	std::mt19937	gen(rd());
	std::uniform_int_distribution<int>	dis(0, 4);

	if (Energy_points >= 25)
		cast_valuthnter(target, dis(gen));
	else
		std::cout << "Out of energy!!! No skill cast!" << std::endl;
}

void	FlagTrap::rangedAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "range"\
	<<", causing <" << Ranged_attack_damage\
	<<"> points of damage!\n# FlagTrap:: rangedAttack!!!"\
	<< std::endl;
}

void	FlagTrap::meleeAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "melee"\
	<<", causing <" << Melee_attack_damage\
	<<"> points of damage!\n# FlagTrap:: meleeAttack!!!"\
	<< std::endl;
}
