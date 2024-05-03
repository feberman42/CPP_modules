/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:13:21 by feberman          #+#    #+#             */
/*   Updated: 2024/05/03 09:39:05 by feberman         ###   ########.fr       */
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
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap was destroyed" << std::endl;
	return ;
}

void	FragTrap::highFive(void)
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << " cannot give you a high five, beacuse it's dead." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " doesn't have the energy to give a high five." << std::endl;
	else
	{
		std::cout << this->_name << " greets you with the biggest high five." << std::endl;
		this->_energyPoints--;
	}
}

std::ostream	&operator<<(std::ostream &os, FragTrap const &c)
{
	c.print(os);
	return (os);
}
