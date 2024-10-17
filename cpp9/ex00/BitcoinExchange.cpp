/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:38:58 by feberman          #+#    #+#             */
/*   Updated: 2024/10/17 21:52:25 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	extract_data_line(std::string &line, std::map<std::string, float> &data);

BitcoinExchange::BitcoinExchange(void)
{
	if (loadFile("data.csv") == false)
		std::cerr << "Error: Couldn't read database." << std::endl;
	return ;
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
	if (this == &rhs)
		return *this;
	this->_data.clear();
	_data.insert(rhs._data.begin(), rhs._data.end());
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange was destroyed" << std::endl;
	return ;
}

bool	BitcoinExchange::loadFile(const char *path)
{
	std::ifstream	file;
	std::string		line;

	file.open(path);
	if (file.is_open() == false)
		return (false);
	std::getline(file, line);
	while (file.eof() == false)
	{
		std::getline(file, line);
		if (line.length() == 0)
			continue ;
		if (extract_data_line(line, _data) == false)
			std::cerr << "Skipped invalid line in database!" << std::endl;
	}
	return (true);
}

void	BitcoinExchange::calculate(const char *path) const
{
	std::ifstream	file;
	std::string		line;

	file.open(path);
	if (file.is_open() == false)
	{
		std::cerr << "Error: Couldn't open file. "<< std::endl;
		return ;
	}
	std::getline(file, line);
	while (file.eof() == false)
	{
		std::getline(file, line);
		if (line.length() > 0)
			dbLookup(line);
	}
	return ;
}

void	BitcoinExchange::dbLookup(std::string &line) const
{
	size_t											sep;
	std::string										date;
	float											value;
	std::map<std::string, float>::const_iterator	match;

	sep = line.find('|');
	if (sep == std::string::npos)
	{
		std::cerr << "Error: Bad input => " << line << std::endl;
		return ;
	}
	date = line.substr(0, sep - 1);
	line.erase(0, sep + 2);
	value = strtof(line.c_str(), NULL);
	if (date < _data.begin()->first)
		std::cerr << "Error: Date is too far in the past." << std::endl;
	else if (value < 0)
		std::cerr << "Error: Not a positive number." << std::endl;
	else if (value > 1000)
		std::cerr << "Error: too large a number." << std::endl;
	else
	{
		match = _data.upper_bound(date);
		std::cout << date << " => " << value << " = " << value * ((--match)->second) << std::endl;
	}
	return ;
}

static bool	extract_data_line(std::string &line, std::map<std::string, float> &data)
{
	size_t	sep;
	std::string	key;

	sep = line.find(',');
	if (sep == std::string::npos)
		return (false);
	key = line.substr(0, sep);
	line.erase(0, sep + 1);
	data[key] = strtof(line.c_str(), NULL);
	return (true);
}
