/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:36:10 by feberman          #+#    #+#             */
/*   Updated: 2024/05/02 13:01:08 by feberman         ###   ########.fr       */
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
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap was destroyed" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
		std::cout
	std::cout << this->_name << " attacks " << target << ", causing " << \
		this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{

}

void	ClapTrap::print(std::ostream &os) const
{
	os << this->_name << std::endl;
	os << "HP: " << this->_hitPoints << std::endl;
	os << "EP: " << this->_energyPoints << std::endl;
	os << "AD: " << this->_attackDamage << std::endl;

}

std::ostream	&operator<<(std::ostream &os, ClapTrap const &c)
{
	c.print(os);
	return (os);
}
