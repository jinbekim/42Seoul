#ifndef RadScorpion_HPP
# define RadScorpion_HPP

# include "Enemy.hpp"

class RadScorpion: public Enemy
{
	private:

	public:
		RadScorpion();
		RadScorpion(const RadScorpion &ref);
		~RadScorpion();
		RadScorpion& operator=(const RadScorpion &ref);

		virtual void takeDamage(int);
};

#endif
