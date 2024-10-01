/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:35:48 by feberman          #+#    #+#             */
/*   Updated: 2024/09/18 16:54:48 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>


int	main(void)
{
	Span	span(77);

	srand(time(NULL));
	for (unsigned int i = 0; i < 77; ++i)
		span.addNumber(rand() % 1000);
	std::cout << span;
	return (0);
}
