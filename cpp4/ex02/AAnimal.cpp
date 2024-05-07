/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:18:09 by feberman          #+#    #+#             */
/*   Updated: 2024/05/06 10:45:28 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "Animal was created" << std::endl;
	this->_brain = new Brain();
	return ;
}

AAnimal::AAnimal(const AAnimal &ref)
{
	std::cout << "Animal was created with copy constructor" << std::endl;
	this->_brain = new Brain();
	*this = ref;
	return ;
}

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
{
	//std::cout << "copy assignment operator called on AAnimal" << std::endl;
	this->_type = rhs._type;
	*this->_brain = *rhs._brain;
	return *this;
}

AAnimal::~AAnimal(void)
{
	delete this->_brain;
	std::cout << "Animal was destroyed" << std::endl;
	return ;
}

void	AAnimal::setType(const std::string &type)
{
	this->_type = type;
}

const std::string	&AAnimal::getType(void) const
{
	return (this->_type);
}

Brain	*AAnimal::getBrain(void) const
{
	return (this->_brain);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "The AAnimal makes AAnimal noises." << std::endl;
}

std::ostream	&operator<<(std::ostream &os, AAnimal const &c)
{
	(void)c;
	os << "Add stream overload for AAnimal" << std::endl;
	return (os);
}
