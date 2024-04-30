/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:53:17 by feberman          #+#    #+#             */
/*   Updated: 2024/04/30 14:00:23 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void):_x(0), _y(0)
{
	// std::cout << "Point was created" << std::endl;
	return ;
}

Point::Point(const float x, const float y):_x(Fixed(x)), _y(Fixed(y))
{
	// std::cout << "Point was created with float constructor" << std::endl;
	return ;
}

Point::Point(const Point &ref): _x(ref.get_x()), _y(ref.get_y())
{
	// std::cout << "Point was created with copy constructor" << std::endl;
	return ;
}

Point	&Point::operator=(const Point &rhs)
{
	// std::cout << "copy assignment operator wont have an effect due to const values" << std::endl;
	(void)rhs;
	return *this;
}

Point::~Point(void)
{
	//std::cout << "Point was destroyed" << std::endl;
	return ;
}

const Fixed	&Point::get_x(void) const
{
	return (this->_x);
}

const Fixed	&Point::get_y(void) const
{
	return (this->_y);
}

