#ifndef ZombieHorde_HPP
# define ZombieHorde_HPP

# include "Zombie.hpp"
# include <ctime>
# include <cstdlib>
# include <random>

class ZombieHorde
{
	private:
		const int	num;
		Zombie*		horde;
	public:
		void	announce();
		ZombieHorde(int N);
		~ZombieHorde();
};

#endif
