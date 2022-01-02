#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>
# include <string>
# include <random>
# include <unistd.h>

class ClapTrap
{
protected:
	ClapTrap();

	std::string	Name;
	int	Level;
	int	Hit_points;
	int	Energy_points;
	int	Max_hit_points;
	int	Max_energy_points;
	int	Melee_attack_damage;
	int	Ranged_attack_damage;
	int	Armor_damage_reduction;
	int cal_damage(unsigned int amount) const;
	int cal_repair(unsigned int amount) const;
	void copy(const ClapTrap &ref);
public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &ref);
	virtual ~ClapTrap();
	ClapTrap& operator=(const ClapTrap &ref);

	virtual void	rangedAttack(std::string const & target);
	virtual void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	std::string	getName(void);
};

#endif
