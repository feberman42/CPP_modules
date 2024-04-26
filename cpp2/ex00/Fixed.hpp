/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:15:18 by feberman          #+#    #+#             */
/*   Updated: 2024/04/24 14:30:18 by feberman         ###   ########.fr       */
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
		Fixed	&operator=(const Fixed &rhs);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					value;
		static const int	fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &c);

#endif
