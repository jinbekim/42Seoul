#ifndef TacticalMarine_HPP
# define TacticalMarine_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
	public:
		TacticalMarine();
		TacticalMarine(const TacticalMarine &ref);
		TacticalMarine& operator=(const TacticalMarine &ref);
		virtual ~TacticalMarine();

		virtual ISpaceMarine* clone() const;
		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
};

#endif
