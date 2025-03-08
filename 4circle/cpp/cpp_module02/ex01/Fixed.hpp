#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int	value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const	Fixed& ohter);
	Fixed& operator = (const Fixed& other);
	~Fixed();

	Fixed(const int n);
	Fixed(const float n);

	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator << (std::ostream& out, const Fixed& fixed);

#endif