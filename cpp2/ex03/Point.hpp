/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:46:26 by feberman          #+#    #+#             */
/*   Updated: 2024/04/30 12:01:09 by feberman         ###   ########.fr       */
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

	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif
