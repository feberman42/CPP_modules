/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:34:55 by feberman          #+#    #+#             */
/*   Updated: 2024/11/29 10:35:09 by feberman         ###   ########.fr       */
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
	std::clock_t	listStart;
	std::clock_t	listEnd;
	double			listTime;

	if (validate_input(argc, argv) == false)
		return (1); 
	vecStart = std::clock();
	sortVector(argc, argv, true);
	vecEnd = std::clock();
	vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000;
	listStart = std::clock();
	sortVector(argc, argv, true);
	listEnd = std::clock();
	listTime = static_cast<double>(listEnd - listStart) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector:\t" << vecTime << " ms" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list:\t" << listTime << " ms" << std::endl;
}
