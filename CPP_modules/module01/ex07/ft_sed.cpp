#include "ft_sed.hpp"

std::string	ft_sed::core(const std::string &line, const std::string &s1, const std::string &s2){
	std::stringstream ss;

	int	i, j = 0;
	while (line[j]){
		i = 0;
		while (line[j + i] == s1[i])
			i++;
		if (i == (int)s1.length()){
			ss << s2;
			j += i;
		}
		else{
			ss << line[j];
			j++;
		}
	}
	return (ss.str());
}


void	ft_sed::replace(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream	source(filename);
	std::ofstream	replace(filename + ".replace");
	std::string		line;

	if (source.fail() || replace.fail())
		throw "file open";
	if (!s1.length() || !s2.length() || !filename.length())
		throw "lengths";
	while (getline(source, line)){
		replace << ft_sed::core(line, s1, s2);
		if (!source.eof())
			replace << "\n";
	}
	source.close();
	replace.close();
}
