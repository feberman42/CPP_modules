/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:59:14 by feberman          #+#    #+#             */
/*   Updated: 2024/04/10 10:18:06 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	//std::cout << "Harl was created" << std::endl;
	return ;
}

Harl::~Harl(void)
{
	//std::cout << "Harl was destroyed" << std::endl;
	return ;
}

void	Harl::complain(std::string level) const
{
	void	(Harl::*f[4])(void) const = \
		{&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = -1;

	while (++i < 4)
		if (level == levels[i])
			break ;

	switch (i)
	{
	case 0:
		(this->*(f[0]))();
		(this->*(f[1]))();
		(this->*(f[2]))();
		(this->*(f[3]))();
		break;
	case 1:
		(this->*(f[1]))();
		(this->*(f[2]))();
		(this->*(f[3]))();
		break;
	case 2:
		(this->*(f[2]))();
		(this->*(f[3]))();
		break;
	case 3:
		(this->*(f[3]))();
		break;
	default:
		std::cerr << level << ": Not a harl level." << std::endl;
		break;
	}
}

void	Harl::_debug(void) const
{
	std::cout << "DEBUG: I love having extra bacon for my "\
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "\
		<< "I really do!" << std::endl;
	return ;	
}

void	Harl::_info(void) const
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. "\
		<< "You didn't put enough bacon in my burger! "\
		<< "If you did, I wouldn't be asking for more!" << std::endl;
	return ;
}

void	Harl::_warning(void) const
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. "\
		<< "I've been coming for years whereas you started working here "\
		<< "since last month." << std::endl;
	return ;
}

void	Harl::_error(void) const
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now."
		<< std::endl;
	return ;
}
