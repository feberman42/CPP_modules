/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:01:40 by feberman          #+#    #+#             */
/*   Updated: 2024/02/23 16:18:54 by feberman         ###   ########.fr       */
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

void	PhoneBook::new_entry(void)
{
	std::string	buf;

	std::cout << "First name: ";
	std::cin >> buf;
	this->contacts[this->active].first_name.assign(buf);
	std::cout << "Last name: ";
	std::cin >> buf;
	this->contacts[this->active].last_name.assign(buf);
	std::cout << "Nick name: ";
	std::cin >> buf;
	this->contacts[this->active].nick_name.assign(buf);
	std::cout << "Phone number: ";
	std::cin >> buf;
	this->contacts[this->active].phone_number.assign(buf);
	std::cout << "Darkest secret: ";
	std::cin >> buf;
	this->contacts[this->active].secret.assign(buf);
	this->active++;
	if (this->active == 8)
		this->active = 0;
}

std::ostream	&operator<<(std::ostream &os, PhoneBook const &c)
{
	c.print_contacts();
	return (os);
}

void	PhoneBook::print_contacts(void) const
{
	int	i;

	i = 0;
	while (i < 8)
		std::cout << this->contacts[i++] << std::endl;
}
