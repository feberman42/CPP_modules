/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:04 by feberman          #+#    #+#             */
/*   Updated: 2024/02/27 13:12:44 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	// std::cout << "Contact constructor called." << std::endl;
	return ;
}
Contact::~Contact(void)
{
	// std::cout << "Contact destructor called." << std::endl;
	return ;
}

std::string	Contact::get_first_name(void) const
{
	return (this->first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->last_name);
}

std::string	Contact::get_nick_name(void) const
{
	return (this->nick_name);
}

std::string	Contact::get_phone_number(void) const
{
	return (this->phone_number);
}

std::string	Contact::get_secret(void) const
{
	return (this->secret);
}

void	Contact::set_first_name(std::string const str)
{
	this->first_name.assign(str);
	return ;
}

void	Contact::set_last_name(std::string const str)
{
	this->last_name.assign(str);
	return ;
}

void	Contact::set_nick_name(std::string const str)
{
	this->nick_name.assign(str);
	return ;
}

void	Contact::set_phone_number(std::string const str)
{
	this->phone_number.assign(str);
	return ;
}

void	Contact::set_secret(std::string const str)
{
	this->secret.assign(str);
	return ;
}
std::ostream	&operator<<(std::ostream &os, Contact const &c)
{
	os << "First name: " << c.get_first_name() << std::endl;
	os << "Last name: " << c.get_first_name() << std::endl;
	os << "Nick name: " << c.get_nick_name() << std::endl;
	os << "Phone number: " << c.get_phone_number() << std::endl;
	os << "Darkest secret: " << c.get_secret() << std::endl;
	return (os);
}
