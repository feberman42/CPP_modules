#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void): _value(0)
{
	// std::cout << "Fixed was created" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &ref)
{
	// std::cout << "Fixed was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Fixed was created with integer contructor" << std::endl;
	this->_value = value << Fixed::_fractionalBits;
	return ;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Fixed was created with float contructor" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_fractionalBits));
	return ;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->_value > rhs._value);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_value < rhs._value);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_value >= rhs._value);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_value <= rhs._value);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_value != rhs._value);
}

Fixed	&Fixed::operator++()
{
	(this->_value)++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	(this->_value)--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	(this->_value)++;
	return (old);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	(this->_value)--;
	return (old);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	ret;
	
	ret._value = (this->_value + rhs._value);
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	ret;
	
	ret._value = (this->_value - rhs._value);
	return (ret);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	ret(this->toFloat() * rhs.toFloat());

	return (ret);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	ret(this->toFloat() / rhs.toFloat());

	return (ret);
}

Fixed::~Fixed(void)
{
	// std::cout << "Fixed was destroyed" << std::endl;
	return ;
}

float	Fixed::toFloat(void) const
{
	return (this->_value / (float)(1 << Fixed::_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_fractionalBits);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	// std::cout << "setRawBits called" << std::endl;
	this->_value = raw;
	return ;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &c)
{
	os << c.toFloat();
	return (os);
}
