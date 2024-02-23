/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:04 by feberman          #+#    #+#             */
/*   Updated: 2024/02/23 15:25:47 by feberman         ###   ########.fr       */
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
	(void)c;
	os << "Contact print called." << std::endl;
	return (os);
}
