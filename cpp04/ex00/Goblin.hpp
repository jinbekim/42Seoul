#ifndef Goblin_HPP
# define Goblin_HPP

# include "Victim.hpp"

class Goblin : public Victim
{

	public:
		Goblin(const std::string& name);
		Goblin(const Goblin &ref);
		~Goblin();
		Goblin& operator=(const Goblin &ref);

		void	getPolymorphed() const;
		void	print_intro(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Goblin &goblin);

#endif
