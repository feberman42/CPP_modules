/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:35:51 by feberman          #+#    #+#             */
/*   Updated: 2024/11/19 15:48:13 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdint.h>

static bool	is_num(const char *str);
static int	ft_atoi(const char *str);

bool	validate_input(int argc, char *argv[])
{
	std::vector<int>			vec;
	std::vector<int>::iterator	it;
	int							i;
	int							num;

	if (argc < 2)
		return (false);
	i = 1;
	while (i < argc)
	{
		if (is_num(argv[i]) == false)
		{
			std::cerr << "Invalid input: \"" << argv[i] << "\"" << std::endl;
			return (false);
		}
		num = ft_atoi(argv[i]);
		if (num < 0)
		{
			std::cerr << "Invalid input: \"" << argv[i] << "\"" << std::endl;
			return (false);
		}
		it = std::lower_bound(vec.begin(), vec.end(), num);
		if (it != vec.end() && *it == num)
		{
			std::cerr << "Double value: " << num << std::endl;
			return (false);
		}
		vec.insert(it, num);
		++i;
	}
	return (true);
}

static bool	is_num(const char *str)
{
	std::size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		++i;
	}
	if (i == 0)
		return (false);
	return (true);
}

static int	ft_atoi(const char *str)
{
	long	num;

	if (std::strlen(str) > 10)
		return (-1);
	num = std::strtol(str, NULL, 10);
	if (num > INT32_MAX)
		return (-1);
	return (num);
}
