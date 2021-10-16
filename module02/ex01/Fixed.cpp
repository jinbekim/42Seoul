#include "Fixed.hpp"

Fixed::Fixed():fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int parameter){
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = (parameter << Fixed::fractional_bit);
}

Fixed::Fixed(const float parameter){
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = roundf(parameter * (1 << Fixed::fractional_bit));
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

float	Fixed::toFloat(void) const{
	return ((float)this->fixed_point_value / (float)(1 << fractional_bit));
}

int		Fixed::toInt(void) const{
	return (this->fixed_point_value >> fractional_bit);
}

Fixed& Fixed::operator=(const Fixed &ref)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixed_point_value = ref.fixed_point_value;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed &ref){
	os << ref.toFloat();
	return (os);
}
