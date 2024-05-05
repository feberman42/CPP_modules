/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:59:46 by feberman          #+#    #+#             */
/*   Updated: 2024/05/05 14:12:16 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat was created" << std::endl;
	this->_type = "Wrong cat";
	return ;
}

WrongCat::WrongCat(const WrongCat &ref): WrongAnimal()
{
	std::cout << "WrongCat was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	//std::cout << "copy assignment operator called on WrongCat" << std::endl;
	this->_type = rhs._type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat was destroyed" << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: Meow." << std::endl;
}

std::ostream	&operator<<(std::ostream &os, WrongCat const &c)
{
	(void)c;
	os << "Add stream overload for WrongCat" << std::endl;
	return (os);
}
