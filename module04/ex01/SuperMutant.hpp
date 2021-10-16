#ifndef SuperMutant_HPP
# define SuperMutant_HPP

# include "Enemy.hpp"

class SuperMutant: public Enemy
{
	private:

	public:
		SuperMutant();
		SuperMutant(const SuperMutant &ref);
		~SuperMutant();
		SuperMutant& operator=(const SuperMutant &ref);

		virtual void takeDamage(int);
};

#endif
