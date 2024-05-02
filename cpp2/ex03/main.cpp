/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:14:53 by feberman          #+#    #+#             */
/*   Updated: 2024/04/30 15:21:51 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bsp.hpp"

int main( void )
{
	Point	p1(0.4f, 0.1f);
	Point	p2(-0.34f, 102.07f);
	Point	p3(32.0f, 0.2f);
	Point	x1(1.0f, 1.0f);
	Point	x2(-1.0f, 1.0f);
	Point	x3(0.0f, 0.0f);

	std::cout << bsp(p1, p2, p3, x1) << std::endl;
	std::cout << bsp(p1, p2, p3, x2) << std::endl;
	std::cout << bsp(p1, p2, p3, x3) << std::endl;

	return (0);
}
