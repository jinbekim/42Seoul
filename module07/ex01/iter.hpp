#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>

template<typename T>
void	iter(T* array, int lengthOfArray, void (*calledForEach)(const T&))
{
	for (int i = 0; i < lengthOfArray; ++i)
		calledForEach(array[i]);
}

template<typename T>
void	print(const T& a)
{
	std::cout << a << " ";
}

#endif
