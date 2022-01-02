#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	{
		std::vector<int> vec(5, 5);
		for (int i = 0; i < 5; i++)
			vec[i] = i;
		std::vector<int>::iterator found = easyfind(vec, 2);
		if (found == vec.end())
			std::cout << "cannot find 2 in vector" << std::endl;
		else
			std::cout << "found 2 in vector " << *found << std::endl;
		if (easyfind(vec, 99) == vec.end())
			std::cout << "99 not found in vector" << std::endl;
	}
	std::vector<int> vector;
	std::list<int> list;

	vector.push_back(40);
	vector.push_back(30);
	vector.push_back(20);
	vector.push_back(10);

	list.push_back(40);
	list.push_back(30);
	list.push_back(20);
	list.push_back(10);


	std::vector<int>::iterator find = easyfind(vector, 10);
	if (find == vector.end())
		std::cout << "not found!" << std::endl;
	else
		std::cout << *find << std::endl;
	std::list<int>::iterator ff = easyfind(list, 10);
	if (ff == list.end())
		std::cout << "not found!" << std::endl;
	else
		std::cout << *ff << std::endl;
	return 0;
}
