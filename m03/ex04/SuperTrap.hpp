#ifndef SuperTrap_HPP
# define SuperTrap_HPP

# include "NinjaTrap.hpp"

class SuperTrap: virtual public NinjaTrap, virtual public FlagTrap
{
	private:
		/* data */
	public:
		SuperTrap(const std::string &name);
		SuperTrap(const SuperTrap &ref);
		virtual ~SuperTrap();
		SuperTrap& operator=(const SuperTrap &ref);
		void	meleeAttack(std::string const & target);
		void	rangedAttack(std::string const & target);
};

#endif
