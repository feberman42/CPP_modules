/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:13:21 by feberman          #+#    #+#             */
/*   Updated: 2024/05/02 22:00:31 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap was created" << std::endl;
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "FragTrap " << name << " was created" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &ref): ClapTrap()
{
	std::cout << "FragTrap was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	//std::cout << "copy assignment operator called on FragTrap" << std::endl;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap was destroyed" << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &os, FragTrap const &c)
{
	c.print(os);
	return (os);
}
