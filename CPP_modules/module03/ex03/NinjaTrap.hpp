#ifndef NinjaTrap_HPP
# define NinjaTrap_HPP

# include "FlagTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: public virtual ClapTrap
{
	private:
	public:
		NinjaTrap(const std::string &Name);
		NinjaTrap(const NinjaTrap &ref);
		virtual ~NinjaTrap();
		NinjaTrap& operator=(const NinjaTrap &ref);

		void	ninjaShoebox(ClapTrap& target);
		void	ninjaShoebox(FlagTrap& target);
		void	ninjaShoebox(ScavTrap& target);
		void	ninjaShoebox(NinjaTrap& target);
};

#endif
