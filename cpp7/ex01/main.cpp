/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:43:52 by feberman          #+#    #+#             */
/*   Updated: 2024/07/09 19:54:07 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstdlib>

int	main(void)
{
	{
		int	int_arr[10];
		srand(time(NULL));
		for(size_t i = 0; i < 10; i++)
		{
			int_arr[i] = rand() % 100;
		}
		iter(int_arr, 10, printValue);
	}
	std::cout << std::endl;
	{
		float float_arr[10];
		srand(time(NULL));
		for(size_t i = 0; i < 10; i++)
		{
			float_arr[i] = 1.0f / (rand() % 100);
		}
		iter(float_arr, 10, printValue);
	}

}
