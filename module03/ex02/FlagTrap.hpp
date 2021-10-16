#ifndef FlagTrap_HPP
# define FlagTrap_HPP

# include "ClapTrap.hpp"

enum	e_skill{
	fire_storm,
	thunder_strom,
	water_storm,
	electric_storm,
	tornado_storm,
};

class FlagTrap : virtual public ClapTrap
{
protected:
	FlagTrap();
	static std::string skill[5];
	void	cast_valuthnter(std::string const &target, int num);

public:
	FlagTrap(const std::string &name);
	FlagTrap(const FlagTrap &ref);
	~FlagTrap();
	FlagTrap& operator=(const FlagTrap &ref);
	void	vaulthunter_dot_exe(std::string const & target);
};

#endif
