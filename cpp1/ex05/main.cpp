/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:33:23 by feberman          #+#    #+#             */
/*   Updated: 2024/03/25 13:26:28 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("test");
	harl.complain("DEBUG");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("WARNING");
	
	return (0);
}
