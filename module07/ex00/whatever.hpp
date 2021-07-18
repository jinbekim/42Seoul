#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T& a,T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<> void swap<double>(double& a, double& b)
{
	double tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T&	min(T& a, T&b)
{
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
T&	max(T& a, T& b)
{
	if (a > b)
		return a;
	else
		return b;
}

class
Awesome {
	public:
		Awesome( int n ) : _n( n ) {}
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
	private:
		int _n;
};

#endif
