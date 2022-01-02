#ifndef Squad_HPP
# define Squad_HPP

# include "ISquad.hpp"
# include "TacticalMarine.hpp"

class Squad: public ISquad
{
	private:
		int				Num;
		ISpaceMarine	**Unit;
	public:
		Squad();
		Squad(const Squad &ref);
		Squad& operator=(const Squad &ref);
		virtual ~Squad();

		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);
};

#endif
