#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		int cal_damage(unsigned int amount) const;
		int cal_repair(unsigned int amount) const;
		static std::string	challenges[5];
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &ref);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &ref);

		void	challengeNewcomer(void);
};

#endif
