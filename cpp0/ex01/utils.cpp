/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:52:39 by feberman          #+#    #+#             */
/*   Updated: 2024/02/25 12:15:44 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string	get_input(const char *prompt)
{
	std::string	buf;

	std::cout << prompt;
	std::getline(std::cin, buf);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
	return (buf);
}

std::string	truncate(const std::string str, long unsigned int width, const char *terminator)
{
	if (str.length() <= width)
		return (str);
	return (str.substr(0, width - std::string(terminator).length()) + terminator);
}