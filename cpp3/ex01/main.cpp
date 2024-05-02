/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:51:02 by feberman          #+#    #+#             */
/*   Updated: 2024/05/02 19:13:46 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap freddy("Freddy");

	freddy.print(std::cout);
	freddy.attack("Pupsi");
	freddy.guardGate();
	freddy.takeDamage(120);
	freddy.beRepaired(3);
	freddy.guardGate();
	freddy.print(std::cout);

	return (0);
}
