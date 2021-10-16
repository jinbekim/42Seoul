#ifndef AWeapon_HPP
# define AWeapon_HPP

# include <iostream>
# include <string>

class AWeapon
{
	protected:
		AWeapon();

		std::string		Name;
		unsigned int	APCost;
		unsigned int	Damage;
		void	copy(const AWeapon& ref);
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(const AWeapon& ref);
		virtual ~AWeapon();
		AWeapon& operator=(const AWeapon& ref);

		const std::string& getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0; //sound & lighting effects
};

#endif
