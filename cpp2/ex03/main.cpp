/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:14:53 by feberman          #+#    #+#             */
/*   Updated: 2024/04/30 13:52:14 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bsp.hpp"

int main( void )
{
	Point	p1(0.0, 0.0);
	Point	p2(0.0, 10.0);
	Point	p3(10.0, 0.0);
	Point	x(1.0, 1.0);

	if (bsp(p1, p2, p3, x) == true)
		std::cout << "Yep" << std::endl;
	return (0);
}
