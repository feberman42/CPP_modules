/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:28:20 by feberman          #+#    #+#             */
/*   Updated: 2024/02/28 15:39:18 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

int	main(void)
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << std::setw(30) << "Memory adress of str: " << &str << std::endl;
	std::cout << std::setw(30) << "Memory adress in stringPTR: " << stringPTR << std::endl;
	std::cout << std::setw(30) << "Memory adress in stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(30) << "Value of str: " << str << std::endl;
	std::cout << std::setw(30) << "Value at stringPTR: " << *stringPTR << std::endl;
	std::cout << std::setw(30) << "Value at stringREF: " << stringREF << std::endl;

	return (0);
}
