/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:11 by feberman          #+#    #+#             */
/*   Updated: 2024/02/25 15:16:08 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <limits>


int	main(void)
{
	PhoneBook 	pb;
	std::string	buf;

	while (true)
	{
		buf = get_input("> ");
		if (buf.compare("EXIT") == 0)
			return (0);
		else if (buf.compare("ADD") == 0)
			pb.new_entry();	
		else if (buf.compare("SEARCH") == 0)
		{
			std::cout << pb << std::endl;
			buf = get_input("Select contact by index[0-7]: ");
			if (buf.length() != 1 || buf[0] < '0' || buf[0] > '7')
				std::cout << buf << " is not a valid index [0-7]" << std::endl;
			else
				pb.print_contact(buf.at(0) - '0');
		}
		else
		{
			std::cout << "Command not found." << std::endl;
			std::cout << "Use ADD, SEARCH or EXIT" << std::endl;
		}
	}
	return (0);
}
