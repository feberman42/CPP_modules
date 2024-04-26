/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:15:18 by feberman          #+#    #+#             */
/*   Updated: 2024/04/26 17:38:28 by feberman         ###   ########.fr       */
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
		Fixed	&operator=(const Fixed &rhs);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &c);

#endif
