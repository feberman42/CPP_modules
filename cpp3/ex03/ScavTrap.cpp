/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:26:13 by feberman          #+#    #+#             */
/*   Updated: 2024/05/03 11:44:40 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("ScavTrap")
{
	std::cout << "ScavTrap was created" << std::endl;
	this->_hitPoints = ScavTrap::_defaultHitPoints;
	this->_energyPoints = ScavTrap::_defaultEnergyPoints;
	this->_attackDamage = ScavTrap::_defaultAttackDamage;
	return ;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " was created" << std::endl;
	this->_hitPoints = ScavTrap::_defaultHitPoints;
	this->_energyPoints = ScavTrap::_defaultEnergyPoints;
	this->_attackDamage = ScavTrap::_defaultAttackDamage;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &ref): ClapTrap()
{
	std::cout << "ScavTrap was created with copy constructor" << std::endl;
	
	*this = ref;
	return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	//std::cout << "copy assignment operator called on ScavTrap" << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap was destroyed" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << " cannot attack, because it's dead." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " doesn't have energy to attack." << std::endl;
	else
	{
		std::cout << this->_name << " attacks " << target << " with all its ScavTrap power, causing " << \
			this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	return ;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << " cannot switch to Gate keeper mode, because it's dead." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " doesn't have energy to switch to Gate keeper mode." << std::endl;
	else
	{
		std::cout << this->_name << " switched to Gate keeper mode" << std::endl;
		this->_energyPoints--;
	}
	return ;
}

std::ostream	&operator<<(std::ostream &os, ScavTrap const &c)
{
	c.print(os);
	return (os);
}
