/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:06:50 by feberman          #+#    #+#             */
/*   Updated: 2024/06/24 15:03:32 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <errno.h>

static bool	handlePseudoLiterals(const std::string &input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		return (true);
	}
	if (input == "nan" || input == "+inf" || input == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return (true);
	}
	return (false);
}

static bool	handleInt(const std::string &input)
{
	for (long unsigned int i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
			continue ;
		if (std::isdigit(input[i]) == 0)
			return (false);
	}

	long	num = std::strtol(input.c_str(), NULL, 10);
	if (num > std::numeric_limits<int>::max())
	{
		std::cerr << "Literal is too big for an integer." << std::endl;
		return (true);
	}
	else if (num < std::numeric_limits<int>::min())
	{
		std::cerr << "Literal is too small for an integer." << std::endl;
		return (true);
	}
	
	if (num > 255 || num < 0 || std::isprint(num) == 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
	return (true);
}

static bool	handleChar(const std::string &input)
{
	if (input.length() != 1)
		return (false);
	if (std::isprint(input[0]) == 0)
		return (false);
	if (std::isdigit(input[0]) != 0)
		return (handleInt(input));
	std::cout << "char: '" << input << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
	return (true);
}

static bool	handleDouble(const std::string &input)
{
	for (long unsigned int i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
			continue ;
		if (std::isdigit(input[i]) == 0 && input[i] != '.')
			return (false);
	}
	if (input.find_first_of('.') != input.find_last_of('.') || input.find_first_of('.') == std::string::npos)
		return (false);
	
	long double	num = std::strtold(input.c_str(), NULL);
	if (num > std::numeric_limits<double>::max())
	{
		std::cerr << "Literal is too big for a double." << std::endl;
		return (true);
	}
	else if (num < -1 * std::numeric_limits<double>::max())
	{
		std::cerr << "Literal is too small for a double." << std::endl;
		return (true);
	}

	if (num > 255 || num < 0 || std::isprint(num) == 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	if (num > std::numeric_limits<float>::max() || num < -1 * std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << num << std::endl;
	return (true);
}

void	ScalarConverter::convert(const std::string &input)
{
	if (handlePseudoLiterals(input))
		return ;
	
	if (handleChar(input))
		return ;

	if (handleInt(input))
		return ;

	if (handleDouble(input))
		return ;

	std::cerr << "Literal: '" << input << "' not recognised." << std::endl;
	return ;
}
