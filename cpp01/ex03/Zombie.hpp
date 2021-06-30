#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
private:
	std::string	name;
	std::string	type;
public:
	Zombie();
	Zombie(std::string &name, std::string &type);
	void	SetNameType(std::string &name, std::string &type);
	~Zombie();
	void	announce();
};

#endif
