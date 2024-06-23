/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:06:50 by feberman          #+#    #+#             */
/*   Updated: 2024/06/23 19:04:28 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>

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

	int	num = std::atoi(input.c_str());
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

void	ScalarConverter::convert(const std::string &input)
{
	if (handlePseudoLiterals(input))
		return ;
	
	if (handleChar(input))
		return ;

	if (handleInt(input))
		return ;

	std::cerr << "Literal: '" << input << "' not recognised." << std::endl;
	return ;
}
