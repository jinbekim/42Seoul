#ifndef PlasmaRifle_HPP
# define PlasmaRifle_HPP

# include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
	private:

	public:
		PlasmaRifle();
		PlasmaRifle(const PlasmaRifle &ref);
		virtual ~PlasmaRifle();
		PlasmaRifle& operator=(const PlasmaRifle &ref);

		virtual void attack() const;
};

#endif
