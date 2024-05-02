/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:03:31 by feberman          #+#    #+#             */
/*   Updated: 2024/05/02 16:16:47 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap freddy("Freddy");
	ClapTrap frodo("Frodo");

	std::cout << std::endl;
	freddy.print(std::cout);
	freddy.attack("Bruno");
	freddy.takeDamage(9);
	freddy.beRepaired(2);
	freddy.beRepaired(2);
	freddy.beRepaired(2);
	freddy.takeDamage(23);
	freddy.attack("the Overlord");
	freddy.print(std::cout);
	std::cout << std::endl;

	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	frodo.attack("Freddy");
	return (0);
}
