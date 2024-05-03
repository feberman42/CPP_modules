/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:51:02 by feberman          #+#    #+#             */
/*   Updated: 2024/05/03 11:55:21 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap freddy("Freddy");

	freddy.print(std::cout);
	freddy.whoAmI();
	freddy.attack("Sauron");
	freddy.beRepaired(4);
	freddy.highFive();
	freddy.takeDamage(932);
	freddy.guardGate();
	freddy.whoAmI();

	return (0);
}
