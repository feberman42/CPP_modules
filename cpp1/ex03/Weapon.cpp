/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:40:45 by feberman          #+#    #+#             */
/*   Updated: 2024/02/28 15:47:40 by feberman         ###   ########.fr       */
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

std::string const	&Weapon::get_type(void) const
{
	return (this->_type);
}
void	Weapon::set_type(std::string type)
{
	this->_type.assign(type);
	return ;
}

std::ostream	&operator<<(std::ostream &os, Weapon const &c)
{
	os << "Add stream overload for Weapon" << std::endl;
	return (os);
}
