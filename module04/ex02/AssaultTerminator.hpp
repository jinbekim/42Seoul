#ifndef AssaultTerminator_HPP
# define AssaultTerminator_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine
{
	public:
		AssaultTerminator(/* args*/);
		AssaultTerminator(const AssaultTerminator &ref);
		AssaultTerminator& operator=(const AssaultTerminator &ref);
		virtual ~AssaultTerminator();

		virtual ISpaceMarine* clone() const;
		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
};

#endif
