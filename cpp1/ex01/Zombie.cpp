/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:04:36 by feberman          #+#    #+#             */
/*   Updated: 2024/02/28 13:48:04 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "nameless zombie was created" << std::endl;
	return ;
}

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << this->_name << " was created" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " was destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::set_name(std::string name)
{
	this->_name.assign(name);
	return ;
}
