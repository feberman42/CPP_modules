/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:22:15 by feberman          #+#    #+#             */
/*   Updated: 2024/10/18 16:18:52 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	int		err;
	double	result;
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}
	result = rpn(argv[1], &err);
	if (err == 0)
	{
		std::cout << result << std::endl;
	}
	return (0);
}
