/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:38:58 by feberman          #+#    #+#             */
/*   Updated: 2024/10/05 16:49:13 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string path)
{
	std::ifstream	file;

	file.open(path);
	if (file.is_open() == false)
		throw std::exception();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	//std::cout << "BitcoinExchange was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	//std::cout << "copy assignment operator called on BitcoinExchange" << std::endl;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange was destroyed" << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &os, BitcoinExchange const &c)
{
	os << "Add stream overload for BitcoinExchange" << std::endl;
	return (os);
}
