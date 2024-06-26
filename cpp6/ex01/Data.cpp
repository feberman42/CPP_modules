/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:34:13 by feberman          #+#    #+#             */
/*   Updated: 2024/06/26 10:08:37 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): _myInt(42), _myString("Hello world")
{
	std::cout << "Data was created" << std::endl;
	return ;
}

Data::~Data(void)
{
	std::cout << "Data was destroyed" << std::endl;
	return ;
}

int			Data::getMyInt(void) const
{
	return (this->_myInt);
}

const std::string	Data::getMyString(void) const
{
	return (this->_myString);
}

void				Data::setMyInt(int value)
{
	this->_myInt = value;
	return ;
}

void				Data::setMyString(const std::string &value)
{
	this->_myString.assign(value);
	return ;
}


std::ostream	&operator<<(std::ostream &os, Data const &c)
{
	os << "\tData\n\tInt: " << c.getMyInt() << "\n\tString: " << c.getMyString() << std::endl;
	return (os);
}
