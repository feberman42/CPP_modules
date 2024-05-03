/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:36:10 by feberman          #+#    #+#             */
/*   Updated: 2024/05/03 09:43:48 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap was created" << std::endl;
	this->_name.assign("ClapTrap");
	return ;
}

ClapTrap::ClapTrap(const std::string &name):
	_hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap was created with name: " << name << std::endl;
	this->_name.assign(name);
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	std::cout << "ClapTrap was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	//std::cout << "copy assignment operator called on ClapTrap" << std::endl;
	this->_name.assign(rhs._name);
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap was destroyed" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << " cannot attack, because it's dead." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " doesn't have energy to attack." << std::endl;
	else
	{
		std::cout << this->_name << " attacks " << target << ", causing " << \
			this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << this->_name << " took " << amount << " damage." << std::endl;
	if (this->_hitPoints == 0)
		std::cout << this->_name << " died." << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << " cannot repair itself, because it's dead." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " doesn't have energy to repair itself." << std::endl;
	else
	{
		this->_hitPoints += amount;
		std::cout << this->_name << " repaired itself for " << amount << " hitpoints." << std::endl;
		this->_energyPoints--;
	}
	return ;
}

void	ClapTrap::print(std::ostream &os) const
{
	os << "\t" << this->_name << std::endl;
	os << "\tHP: " << this->_hitPoints << std::endl;
	os << "\tEP: " << this->_energyPoints << std::endl;
	os << "\tAD: " << this->_attackDamage << std::endl;
}

std::ostream	&operator<<(std::ostream &os, ClapTrap const &c)
{
	c.print(os);
	return (os);
}
