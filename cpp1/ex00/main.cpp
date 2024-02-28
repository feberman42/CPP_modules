/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:18:26 by feberman          #+#    #+#             */
/*   Updated: 2024/02/28 13:38:13 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	peter("Peter");
	Zombie	*hans;

	peter.announce();
	hans = newZombie("Hans");
	if (hans)
	{
		hans->announce();
		peter.announce();
		delete hans;
	}
	randomChump("Freddy");
	return (0);
}
