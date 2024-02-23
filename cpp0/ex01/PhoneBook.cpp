/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:01:40 by feberman          #+#    #+#             */
/*   Updated: 2024/02/23 15:39:23 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called." << std::endl;
	this->active = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called." << std::endl;
	return;
}

Contact	*PhoneBook::get_active_contact(void)
{
	Contact	*c;

	c = &this->contacts[this->active];
	this->active++;
	if (this->active == 8)
		this->active = 0;
	return (c);
}

std::ostream	&operator<<(std::ostream &os, PhoneBook const &c)
{
	(void)c;
	os << "PhoneBook print called." << std::endl;
	return (os);
}
