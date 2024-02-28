/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:18:26 by feberman          #+#    #+#             */
/*   Updated: 2024/02/28 14:01:23 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(7, "Max");
	if (!horde)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return (1);
	}
	for (int i = 0; i < 7; i++)
		horde[i].announce();
	std::cout << std::endl;
	horde[2].set_name("Kars");
	for (int i = 0; i < 7; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
