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
void	display(const T& a)
{
	std::cout << a << " ";
}

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

#endif
