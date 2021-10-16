#ifndef Sorcerer_HPP
# define Sorcerer_HPP

# include "Victim.hpp"
# include "Peon.hpp"
# include "Goblin.hpp"

class Sorcerer
{
	private:
		std::string	name;
		std::string	title;
	public:
		Sorcerer(const std::string &name, const std::string &title);
		Sorcerer(const Sorcerer &ref);
		virtual ~Sorcerer();
		Sorcerer& operator=(const Sorcerer &ref);
		const std::string& get_name() const;
		const std::string& get_title() const;
		void	print_intro(void) const;
		void	polymorph(Victim const &) const;
		void	polymorph(Peon const &) const;
		void	polymorph(Goblin const &) const;
};

std::ostream&	operator<<(std::ostream& os, const Sorcerer &sorcerer);

#endif
