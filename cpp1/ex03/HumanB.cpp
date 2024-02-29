/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:16:36 by feberman          #+#    #+#             */
/*   Updated: 2024/02/29 10:42:33 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	// std::cout << "HumanA was created" << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	//std::cout << "HumanA was destroyed" << std::endl;
	return ;
}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks";
	if (this->_weapon)
		std::cout << " with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << " without a weapon" << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}
