/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:45:19 by feberman          #+#    #+#             */
/*   Updated: 2024/05/07 14:24:50 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	//std::cout << "Ice was created" << std::endl;
	return ;
}

Ice::Ice(const Ice &ref): AMateria("ice")
{
	(void)ref;
	//std::cout << "Ice was created with copy constructor" << std::endl;
	return ;
}

Ice	&Ice::operator=(const Ice &rhs)
{
	(void)rhs;
	std::cerr << "copy assignment operator doesn't work on materias" << std::endl;
	return *this;
}

Ice::~Ice(void)
{
	//std::cout << "Ice was destroyed" << std::endl;
	return ;
}

AMateria	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
