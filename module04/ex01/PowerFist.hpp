#ifndef PowerFist_HPP
# define PowerFist_HPP

# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
	private:

	public:
		PowerFist();
		PowerFist(const PowerFist &ref);
		virtual ~PowerFist();
		PowerFist& operator=(const PowerFist &ref);

		virtual void attack() const;
};

#endif
