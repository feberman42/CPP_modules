/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:08:01 by feberman          #+#    #+#             */
/*   Updated: 2024/05/07 14:24:22 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	//std::cout << "Cure was created" << std::endl;
	return ;
}

Cure::Cure(const Cure &ref): AMateria("cure")
{
	(void)ref;
	//std::cout << "Cure was created with copy constructor" << std::endl;
	return ;
}

Cure	&Cure::operator=(const Cure &rhs)
{
	(void)rhs;
	std::cerr << "copy assignment operator doesn't work on materias" << std::endl;
	return *this;
}

Cure::~Cure(void)
{
	//std::cout << "Cure was destroyed" << std::endl;
	return ;
}

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heels " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
