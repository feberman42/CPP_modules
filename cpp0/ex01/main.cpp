/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:11 by feberman          #+#    #+#             */
/*   Updated: 2024/02/23 15:56:45 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	// PhoneBook 	pb;
	std::string	buf;

	while (true)
	{
		std::cout << "> ";
		std::cin >> buf;
		if (buf.compare("EXIT") == 0)
			return (0);
		else if (buf.compare("ADD") == 0)
		{
			//add new contact
		}
		else if (buf.compare("SEARCH") == 0)
		{
			//search
		}
		else
		{
			std::cout << "Command not found." << std::endl;
			std::cout << "Use ADD, SEARCH or EXIT" << std::endl;
		}
	}
	return (0);
}
