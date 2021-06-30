// 1. read filename
// 2. find s1, replace it as s2
// 3. generate filename.replace
// basic file operations
#include <iostream>
#include <fstream>

int main (int ac, char **av) {
	if (ac < 4)
		return (1);
	std::ofstream	source;
	std::ofstream	result;
	std::string		file_name = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		buf;

	source.open(file_name);
	result.open(file_name + ".replace");

	source.close();
	result.close();
	return 0;
}
