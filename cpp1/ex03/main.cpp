/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:32:11 by feberman          #+#    #+#             */
/*   Updated: 2024/02/29 10:54:58 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("sword");
		jim.attack();
	}
	Weapon	dagger = Weapon("dagger");
	HumanA freddy("Freddy", dagger);
	HumanB kars("Kars");
	kars.setWeapon(dagger);
	freddy.attack();
	kars.attack();
	dagger.setType("words");
	freddy.attack();
	kars.attack();
	return 0;
}
