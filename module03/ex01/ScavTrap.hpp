#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "FlagTrap.hpp"

class ScavTrap
{
	private:
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
		static std::string	challenges[5];
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &ref);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &ref);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer(void);
};

#endif
