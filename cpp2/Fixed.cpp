#include "Fixed.hpp"

Fixed::Fixed(void): value(0)
{
	std::cout << "Fixed was created" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Fixed was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Fixed was created with copy assignment operator" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed was destroyed" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->value = raw;
	return ;
}

std::ostream	&operator<<(std::ostream &os, Fixed const &c)
{
	(void)c;
	os << "Add stream overload for Fixed" << std::endl;
	return (os);
}
