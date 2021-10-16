#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>
# include <cmath> // roundf

class Fixed
{
	private:
		const static int	fractional_bit = 8;
		int	fixed_point_value;
	public:
		Fixed();
		Fixed(const int parameter);
		Fixed(const float parameter);
		Fixed(const Fixed &ref);

		~Fixed();

		Fixed&			operator=(const Fixed &ref);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

// Overloading with global functions
std::ostream&	operator<<(std::ostream& os, const Fixed &ref);

#endif
