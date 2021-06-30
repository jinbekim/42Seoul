#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
private:
	std::string const	name;
	std::string const	type;
public:
	Zombie(std::string const &name, std::string const &type);
	~Zombie();
	void	announce();
};

#endif
