/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:27:10 by feberman          #+#    #+#             */
/*   Updated: 2024/05/05 14:11:57 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat was created" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat(const Cat &ref): Animal()
{
	std::cout << "Cat was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	//std::cout << "copy assignment operator called on Cat" << std::endl;
	this->_type = rhs._type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat was destroyed" << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meow." << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Cat const &c)
{
	(void)c;
	os << "Add stream overload for Cat" << std::endl;
	return (os);
}
