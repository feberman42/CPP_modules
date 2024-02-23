/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:11 by feberman          #+#    #+#             */
/*   Updated: 2024/02/23 16:48:39 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <limits>

int	main(void)
{
	PhoneBook 	pb;
	std::string	buf;

	while (true)
	{
		std::cout << "> ";
		std::cin >> buf;
		if (buf.compare("EXIT") == 0 || std::cin.eof())
			return (0);
		else if (buf.compare("ADD") == 0)
			pb.new_entry();
		else if (buf.compare("SEARCH") == 0)
			std::cout << pb << std::endl;
		else
		{
			std::cout << "Command not found." << std::endl;
			std::cout << "Use ADD, SEARCH or EXIT" << std::endl;
		}
	}
	return (0);
}
