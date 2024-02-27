/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:01:40 by feberman          #+#    #+#             */
/*   Updated: 2024/02/27 13:14:07 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "PhoneBook constructor called." << std::endl;
	this->active = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook destructor called." << std::endl;
	return;
}

void	PhoneBook::new_entry(void)
{
	std::string	buf;

	buf = get_input("First name: ");
	this->contacts[this->active].set_first_name(buf);
	buf = get_input("Last name: ");
	this->contacts[this->active].set_last_name(buf);
	buf = get_input("Nick name: ");
	this->contacts[this->active].set_nick_name(buf);
	buf = get_input("Phone number: ");
	this->contacts[this->active].set_phone_number(buf);
	buf = get_input("Darkest secret: ");
	this->contacts[this->active].set_secret(buf);
	this->next_entry();
}

void	PhoneBook::next_entry(void)
{
	this->active++;
	if (this->active == 8)
		this->active = 0;
}

void	PhoneBook::print_contact(int index) const
{
	std::cout << this->contacts[index] << std::endl;
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
	std::cout << "   " << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << std::endl;
	while (i < 8)
	{
		std::cout << i << "> ";
		std::cout << "|" << std::setw(10) << truncate(this->contacts[i].get_first_name(), 10, ".");
		std::cout << "|" << std::setw(10) << truncate(this->contacts[i].get_last_name(), 10, ".");
		std::cout << "|" << std::setw(10) << truncate(this->contacts[i].get_nick_name(), 10, ".");
		std::cout << "|" << std::setw(10) << truncate(this->contacts[i].get_phone_number(), 10, ".") << "|" << std::endl;
		i++;
	}
	std::cout << "   " << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << std::endl;
}
