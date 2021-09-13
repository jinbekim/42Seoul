#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle():AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &ref):AWeapon("Plasma Rifle", 5, 21)
{
	AWeapon::copy(ref);
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle& PlasmaRifle::operator=(const PlasmaRifle &ref)
{
	AWeapon::copy(ref);
	return (*this);
}

void PlasmaRifle::attack() const
{
	std::cout<<
	"* piouuu piouuu piouuu *"
	<< std::endl;
}
