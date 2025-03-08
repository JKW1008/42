#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int n)
{
	value = n << bits;
}

Fixed::Fixed(const float n)
{
	value = roundf(n * (1 << bits));
}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << bits));
}

int	Fixed::toInt(void) const
{
	return (value >> bits);	
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits(this->value + other.value);
	return (res);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits(this->value - other.value);
	return (res);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits((this->value * other.value) >> bits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits((this->value << bits) / other.value);
	return (res);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->value += 1;
	return	(*this);
}

Fixed&	Fixed::operator--()
{
	this->value -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	res;
	
	res = (*this);
	this->value += 1;
	return (res);
}

Fixed	Fixed::operator--(int)
{
	Fixed	res;

	res = (*this);
	this->value -= 1;
	return (res);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}