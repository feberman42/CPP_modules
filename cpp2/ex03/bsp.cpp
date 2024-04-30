/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:07:21 by feberman          #+#    #+#             */
/*   Updated: 2024/04/30 14:05:48 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

static int	side(Point const &start, Point const &end, Point const &point);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int	abp;
	int	bcp;
	int	cap;

	abp = side(a, b, point);
	std::cout << abp << std::endl;
	bcp = side(b, c, point);
	std::cout << bcp << std::endl;
	cap = side(c, a, point);
	std::cout << cap << std::endl;

	if (abp == bcp && bcp == cap && abp != 0)
		return (true);
	return (false);
}

static int	side(Point const &start, Point const &end, Point const &point)
{
	Fixed	t1;
	Fixed	t2;
	Fixed	t3;
	Fixed	t4;
	float	d;

	t1 = (point.get_x() - start.get_x());
	t2 = (end.get_y() - start.get_y());
	t3 = (point.get_y() - start.get_y());
	t4 = (end.get_x() - start.get_x());
	d = ((t1 * t2) - (t3 * t4)).toFloat();
	std::cout << d << std::endl;
	if (d == 0)
		return (0);
	else if (d < 0)
		return (-1);
	return (1);
}
