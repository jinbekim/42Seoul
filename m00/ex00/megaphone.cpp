#include <iostream>
#include <string>

int	main(int ac, char **av){
	int	i;
	std::string	str;

	i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (av[i])
	{
		str = av[i];
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}
