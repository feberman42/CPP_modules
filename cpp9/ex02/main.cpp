/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:34:55 by feberman          #+#    #+#             */
/*   Updated: 2024/11/28 19:41:47 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pmergeMe.h"
#include <ctime>
#include <iostream>

int	main(int argc, char *argv[])
{
	std::clock_t	vecStart;
	std::clock_t	vecEnd;
	double			vecTime;

	if (validate_input(argc, argv) == false)
		return (1); 
	vecStart = std::clock();
	sortVector(argc, argv, true);
	vecEnd = std::clock();
	vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector:\t" << vecTime << " ms" << std::endl;
}
