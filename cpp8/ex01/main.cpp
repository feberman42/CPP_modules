/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:35:48 by feberman          #+#    #+#             */
/*   Updated: 2024/10/05 13:03:26 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

#define SPAN_SIZE 10

int	main(void)
{
	Span	span(SPAN_SIZE + 5);
	std::vector<int>	vec;

	vec.push_back(42);
	vec.push_back(43);
	vec.push_back(44);
	vec.push_back(46);
	vec.push_back(45);

	srand(time(NULL));
	for (unsigned int i = 0; i < SPAN_SIZE; ++i)
	{
		try
		{
			span.addNumber(rand() % 1000);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
	span.addNumber(vec.begin(), vec.end());
	std::cout << span;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	return (0);
}
