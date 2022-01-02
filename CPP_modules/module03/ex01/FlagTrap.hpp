#ifndef FlagTrap_HPP
# define FlagTrap_HPP

# include <iostream>
# include <string>
# include <random>
# include <unistd.h>

enum	e_skill{
	fire_storm,
	thunder_strom,
	water_storm,
	electric_storm,
	tornado_storm,
};

class FlagTrap
{
private:
	std::string	Name;
	int	Level;
	int	Hit_points;
	const int	Max_hit_points;
	int	Energy_points;
	const int	Max_energy_points;
	const int	Melee_attack_damage;
	const int	Ranged_attack_damage;
	const int	Armor_damage_reduction;
	void		cast_valuthnter(std::string const &target, int num);
	int cal_damage(unsigned int amount) const;
	int cal_repair(unsigned int amount) const;
	static std::string skill[5];
public:
	FlagTrap(const std::string &name);
	FlagTrap(const FlagTrap &ref);
	~FlagTrap();
	FlagTrap& operator=(const FlagTrap &ref);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);
};

#endif
