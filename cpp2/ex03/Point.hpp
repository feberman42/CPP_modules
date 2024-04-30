/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:46:26 by feberman          #+#    #+#             */
/*   Updated: 2024/04/30 13:21:57 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &ref);
		Point	&operator=(const Point &rhs);
		~Point(void);

		const Fixed	&get_x(void) const;
		const Fixed	&get_y(void) const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif
