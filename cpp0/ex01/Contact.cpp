/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:04 by feberman          #+#    #+#             */
/*   Updated: 2024/02/25 12:55:33 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called." << std::endl;
	return ;
}
Contact::~Contact(void)
{
	std::cout << "Contact destructor called." << std::endl;
	return ;
}
		
std::ostream	&operator<<(std::ostream &os, Contact const &c)
{
	os << "First name: " << c.first_name << std::endl;
	os << "Last name: " << c.last_name << std::endl;
	os << "Nick name: " << c.nick_name << std::endl;
	os << "Phone number: " << c.phone_number << std::endl;
	os << "Darkest secret: " << c.secret << std::endl;
	return (os);
}
