#include "Fixed.hpp"

Fixed::Fixed():fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &ref)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixed_point_value = ref.getRawBits();
	return (*this);
}

// that returns the raw value of the fixed point value.
int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_value);
}

// that sets the raw value of the fixed point value
void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_value = raw;
}
