#ifndef Peon_HPP
# define Peon_HPP

# include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(const std::string& name);
		Peon(const Peon &ref);
		virtual ~Peon();
		Peon& operator=(const Peon &ref);

		virtual void	getPolymorphed() const;
};

std::ostream&	operator<<(std::ostream& os, const Peon &peon);

#endif
