#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>

class Fixed
{
	private:
		const static int	fractional_bit = 8;
		int	fixed_point_value;
	public:
		Fixed();
		Fixed(const Fixed &ref);
		~Fixed();
		Fixed& operator=(const Fixed &ref);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
