/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:57:11 by feberman          #+#    #+#             */
/*   Updated: 2024/05/05 14:05:27 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal was created" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout << "WrongAnimal was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	//std::cout << "copy assignment operator called on WrongAnimal" << std::endl;
	this->_type = rhs._type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal was destroyed" << std::endl;
	return ;
}

void	WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
}

const std::string	&WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "This animal makes weird noises." << std::endl;
}

std::ostream	&operator<<(std::ostream &os, WrongAnimal const &c)
{
	(void)c;
	os << "Add stream overload for WrongAnimal" << std::endl;
	return (os);
}
