/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:39:19 by feberman          #+#    #+#             */
/*   Updated: 2024/05/03 11:53:01 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap was created" << std::endl;
	this->_name = "DiamondTap";
	this->_hitPoints = FragTrap::_defaultHitPoints;
	this->_energyPoints = ScavTrap::_defaultEnergyPoints;
	this->_attackDamage = FragTrap::_defaultAttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(const std::string &name):
	ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap was created" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_defaultHitPoints;
	this->_energyPoints = ScavTrap::_defaultEnergyPoints;
	this->_attackDamage = FragTrap::_defaultAttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	//std::cout << "copy assignment operator called on DiamondTrap" << std::endl;
	this->_name = rhs._name;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap was destroyed" << std::endl;
	return ;
}

void	DiamondTrap:: whoAmI(void)
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << " is dead and cannot have an identity crisis now." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " doesn't have the energy for an identity crisis now." << std::endl;
	else
	{
		std::cout << "\t" << this->_name << std::endl << "\t" << ClapTrap::_name << std::endl;
		this->_energyPoints--;
	}
}

std::ostream	&operator<<(std::ostream &os, DiamondTrap const &c)
{
	c.print(os);
	return (os);
}
