#ifndef ZombieEvent_HPP
# define ZombieEvent_HPP

# include "Zombie.hpp"
# include <cstdlib>
# include <ctime>

class ZombieEvent
{
	private:
		std::string	type;
	public:
		void		setZombieType(const std::string &type);
		void		randomChump();
		Zombie*		newZombie(const std::string &name);
};

#endif
