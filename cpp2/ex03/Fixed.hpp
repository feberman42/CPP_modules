/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:15:18 by feberman          #+#    #+#             */
/*   Updated: 2024/04/30 11:09:50 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &ref);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);

		Fixed	&operator=(const Fixed &rhs);
		bool	operator>(const Fixed &rhs);
		bool	operator<(const Fixed &rhs);
		bool	operator>=(const Fixed &rhs);
		bool	operator<=(const Fixed &rhs);
		bool	operator==(const Fixed &rhs);
		bool	operator!=(const Fixed &rhs);
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator*(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);
		
		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &c);

#endif
