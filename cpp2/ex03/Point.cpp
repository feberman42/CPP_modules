/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:53:17 by feberman          #+#    #+#             */
/*   Updated: 2024/04/30 12:03:29 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void):_x(0), _y(0)
{
	//std::cout << "Point was created" << std::endl;
	return ;
}

Point::Point(const float x, const float y):_x(Fixed(x)), _y(Fixed(y))
{
	return ;
}

Point::Point(const Point &ref)
{
	//std::cout << "Point was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

Point	&Point::operator=(const Point &rhs)
{
	std::cout << "copy assignment operator wont have an effect due to const values" << std::endl;
	(void)rhs;
	return *this;
}

Point::~Point(void)
{
	//std::cout << "Point was destroyed" << std::endl;
	return ;
}
