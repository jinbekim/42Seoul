#ifndef Pony_HPP
# define Pony_HPP

# include <iostream>
# include <string>

class Pony
{
	private:
		const std::string& name_;
	public:
		Pony(const std::string& name);
		~Pony();
		void	intro(void);
		void	address(void);
};

#endif
