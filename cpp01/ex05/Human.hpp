#ifndef Human_HPP
# define Human_HPP

# include "Brain.hpp"

class Human
{
	private:
		const Brain brain;
	public:
		Human(/* args*/);
		const Brain		&getBrain() const;
		std::string		identify() const;
};

#endif
