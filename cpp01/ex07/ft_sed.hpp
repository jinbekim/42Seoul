#ifndef ft_sed_HPP
# define ft_sed_HPP

# include <iostream>
# include <fstream>
# include <sstream>

class ft_sed
{
	private:
		static std::string	core(const std::string &line, const std::string &s1, const std::string &s2);
	public:
		ft_sed() = default ;
		~ft_sed() = default ;
		static void replace(const std::string &filename, const std::string &s1, const std::string &s2);
};

#endif
