/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:29:47 by feberman          #+#    #+#             */
/*   Updated: 2024/05/07 10:14:41 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog was created" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog(const Dog &ref): AAnimal()
{
	std::cout << "Dog was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	//std::cout << "copy assignment operator called on Dog" << std::endl;
	this->_type = rhs._type;
	*this->_brain = *rhs._brain;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog was destroyed" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Bark" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Dog const &c)
{
	(void)c;
	os << "Add stream overload for Dog" << std::endl;
	return (os);
}
