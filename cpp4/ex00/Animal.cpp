/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:18:09 by feberman          #+#    #+#             */
/*   Updated: 2024/05/05 14:11:25 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal was created" << std::endl;
	return ;
}

Animal::Animal(const Animal &ref)
{
	std::cout << "Animal was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	//std::cout << "copy assignment operator called on Animal" << std::endl;
	this->_type = rhs._type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal was destroyed" << std::endl;
	return ;
}

void	Animal::setType(const std::string &type)
{
	this->_type = type;
}

const std::string	&Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "The animal makes animal noises." << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Animal const &c)
{
	(void)c;
	os << "Add stream overload for Animal" << std::endl;
	return (os);
}
