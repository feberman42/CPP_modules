/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:51:02 by feberman          #+#    #+#             */
/*   Updated: 2024/05/03 09:42:34 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap freddy("Freddy");

	freddy.print(std::cout);
	freddy.attack("Olaf");
	freddy.highFive();
	freddy.takeDamage(6);
	freddy.beRepaired(2);
	freddy.highFive();
	freddy.highFive();
	freddy.highFive();
	freddy.highFive();
	freddy.highFive();
	freddy.highFive();
	freddy.highFive();
	freddy.highFive();
	freddy.highFive();
	freddy.print(std::cout);
	freddy.takeDamage(200);
	freddy.highFive();
	

	return (0);
}
