/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:38:37 by feberman          #+#    #+#             */
/*   Updated: 2024/11/29 10:54:12 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	BitcoinExchange	btc;
	
	if (argc != 2)
	{
		std::cout << "Usage: ./btc file_path" << std::endl;
		return (1);
	}
	btc.calculate(argv[1]);
}
