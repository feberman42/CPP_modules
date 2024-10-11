/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:38:58 by feberman          #+#    #+#             */
/*   Updated: 2024/10/11 17:37:55 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int	extract_data_line(std::string &line, std::map<std::string, float> &data);

BitcoinExchange::BitcoinExchange(const char *path)
{
	std::ifstream	file;
	std::string		line;

	file.open(path);
	if (file.is_open() == false)
		throw std::exception();
	std::getline(file, line);
	while (file.eof() == false)
	{
		std::getline(file, line);
		extract_data_line(line, _data);
	}
	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << it->first << " = " << it->second << std::endl;
	}
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
// {
// 	//std::cout << "BitcoinExchange was created with copy constructor" << std::endl;
// 	*this = ref;
// 	return ;
// }

// BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
// {
// 	//std::cout << "copy assignment operator called on BitcoinExchange" << std::endl;
// 	return *this;
// }

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange was destroyed" << std::endl;
	return ;
}

// std::ostream	&operator<<(std::ostream &os, BitcoinExchange const &c)
// {
// 	os << "Add stream overload for BitcoinExchange" << std::endl;
// 	return (os);
// }

static int	extract_data_line(std::string &line, std::map<std::string, float> &data)
{
	size_t	sep;
	std::string	key;

	sep = line.find(',');
	if (sep == std::string::npos)
		return (FAIL);
	key = line.substr(0, sep);
	line.erase(0, sep + 1);
	data[key] = strtof(line.c_str(), NULL);
	return (SUCCESS);
}

const char	*BitcoinExchange::InvalidInputData::what(void) const throw()
{
	return ("Data file contains invalid input.");
}
