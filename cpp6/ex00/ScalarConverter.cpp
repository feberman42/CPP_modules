/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:06:50 by feberman          #+#    #+#             */
/*   Updated: 2024/07/01 12:29:47 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <limits>
#include <errno.h>
#include <sstream>

static void	printValue(float value)
{
	if (value == std::floor(value))
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	else
		std::cout << "float: " << value << "f" << std::endl;
}

static void	printValue(double value)
{
	if (value == std::floor(value))
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}

static void	printValue(int value)
{
	std::cout << "Int: " << value << std::endl;
}

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
	char	sign;
	for (long unsigned int i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
		{
			sign = input[0];
			continue ;
		}
		if (std::isdigit(input[i]) == 0)
			return (false);
	}

	int	num = std::atoi(input.c_str());
	std::ostringstream ss;
	if (sign == '+')
		ss << '+';
	if (sign == '-' && num == 0)
		ss << '-';
	ss << num;

	if (input.compare(ss.str()) != 0)
	{
		std::cerr << "Literal doesn't fit an integer." << std::endl;
		return (true);
	}
	
	if (num > 255 || num < 0 || std::isprint(num) == 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	printValue(num);
	printValue(static_cast<float>(num));
	printValue(static_cast<double>(num));
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
	printValue(static_cast<int>(input[0]));
	printValue(static_cast<float>(input[0]));
	printValue(static_cast<double>(input[0]));
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
	
	double	num = std::strtod(input.c_str(), NULL);
	if (num == HUGE_VAL && errno == ERANGE)
	{
		std::cerr << "Literal is too big for a double." << std::endl;
		return (true);
	}
	else if (num == -HUGE_VAL && errno == ERANGE)
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
		printValue(static_cast<int>(num));
	if (num > std::numeric_limits<float>::max() || num < -1 * std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		printValue(static_cast<float>(num));
	printValue(num);
	return (true);
}

static bool	handleFloat(const std::string input)
{
	if (input.length() < 2 || input[input.length() - 1] != 'f')
		return (false);
	for (long unsigned int i = 0; i < input.length() - 1; i++)
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
			continue ;
		if (std::isdigit(input[i]) == 0 && input[i] != '.')
			return (false);
	}
	if (input.find_first_of('.') != input.find_last_of('.'))
		return (false);
	
	float	num = std::strtof(input.c_str(), NULL);
	if (num == HUGE_VALF && errno == ERANGE)
	{
		std::cerr << "Literal is too big for a float." << std::endl;
		return (true);
	}
	else if (num == -HUGE_VALF && errno == ERANGE)
	{
		std::cerr << "Literal is too small for a float." << std::endl;
		return (true);
	}

	if (num > 255 || num < 0 || std::isprint(num) == 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		printValue(static_cast<int>(num));
	printValue(num);
	printValue(static_cast<double>(num));
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
	if (handleFloat(input))
		return ;
	std::cerr << "Literal: '" << input << "' not recognised." << std::endl;
	return ;
}
