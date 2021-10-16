#ifndef Victim_HPP
# define Victim_HPP

# include <iostream>
# include <string>

class Victim
{
	protected:
		Victim();
		std::string	name;
	public:
		Victim(const std::string& name);
		Victim(const Victim &ref);
		virtual ~Victim();
		Victim& operator=(const Victim &ref);

		const std::string& get_name(void) const;
		void	print_intro(void) const;
		virtual void	getPolymorphed() const;
};

std::ostream&	operator<<(std::ostream& os, const Victim &victim);

#endif
