/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:40:45 by feberman          #+#    #+#             */
/*   Updated: 2024/02/29 10:39:53 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	//std::cout << "Weapon was created" << std::endl;
	return ;
}

Weapon::Weapon(std::string type): _type(type)
{
	//std::cout << "Weapon was created" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	//std::cout << "Weapon was destroyed" << std::endl;
	return ;
}

std::string const	&Weapon::getType(void) const
{
	return (this->_type);
}
void	Weapon::setType(std::string type)
{
	this->_type.assign(type);
	return ;
}
