#include "FlagTrap.hpp"

std::string FlagTrap::skill[5] = {
	"fire_storm",
	"thunder_strom",
	"water_storm",
	"electric_storm",
	"tornado_storm"
};

FlagTrap::FlagTrap(const std::string &name):
Name(name),\
Max_hit_points(100),\
Max_energy_points(100),\
Melee_attack_damage(20),\
Ranged_attack_damage(30),\
Armor_damage_reduction(5)
{
	Hit_points = 100;
	Energy_points = 100;
	Level = 1;
}

FlagTrap::FlagTrap(const FlagTrap &ref):
Max_hit_points(100),\
Max_energy_points(100),\
Melee_attack_damage(20),\
Ranged_attack_damage(30),\
Armor_damage_reduction(5)
{
	*this = ref;
}

FlagTrap::~FlagTrap()
{
	std::cout << "# FR4G-TP<" <<this->Name << "> is terminated!" << std::endl;
}

FlagTrap& FlagTrap::operator=(const FlagTrap &ref)
{
	this->Name = ref.Name;
	this->Level = ref.Level;
	this->Hit_points = ref.Hit_points;
	this->Energy_points = ref.Energy_points;
	return (*this);
}

void	FlagTrap::rangedAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "range"\
	<<", causing <" << Ranged_attack_damage\
	<<"> points of damage!\n# rangedAttack!!!"\
	<< std::endl;
}

void	FlagTrap::meleeAttack(std::string const & target){
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> attacks <" << target\
	<<"> at " << "melee"\
	<<", causing <" << Melee_attack_damage\
	<<"> points of damage!\n# meleeAttack!!!"\
	<< std::endl;
}

int FlagTrap::cal_damage(unsigned int amount) const {
	return (\
	(const int)(amount - Armor_damage_reduction) > Hit_points ?\
	Hit_points : amount - Armor_damage_reduction);
}

void	FlagTrap::takeDamage(unsigned int amount){
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

int FlagTrap::cal_repair(unsigned int amount) const {
	return (\
	(const int)(Hit_points + amount) > Max_hit_points ?\
	Max_hit_points - Hit_points : amount);
}

void	FlagTrap::beRepaired(unsigned int amount){
	int	calculated_amount = cal_repair(amount);

	Hit_points += calculated_amount;
	std::cout\
	<<"FR4G-TP <" << Name\
	<<"> is repaired <" << calculated_amount\
	<< "> of Hit_points.\n# Now you have <" << Hit_points\
	<< "> Hit_points."\
	<< std::endl;
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
