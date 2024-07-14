/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:44:46 by feberman          #+#    #+#             */
/*   Updated: 2024/07/14 18:23:13 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	int					intArr[] = {1, 3, 5, 7, 9};
	std::vector<int>	intVec(intArr, intArr + 5);

	for(std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::vector<int>::iterator	found = easyfind(intVec, 5);
	std::cout << *found << " at position " << found - intVec.begin() << std::endl;

	return (0);
}
