#ifndef Brain_HPP
# define Brain_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class Brain
{
	private:
		const std::string name;
	public:
		Brain(const std::string &name);
		std::string	identify() const;
};

#endif
