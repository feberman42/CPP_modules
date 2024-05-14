/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:35:45 by feberman          #+#    #+#             */
/*   Updated: 2024/05/07 14:26:16 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	//std::cout << "AMateria was created" << std::endl;
	return ;
}

AMateria::AMateria(const std::string &type): _type(type)
{
	return ;
}

AMateria::AMateria(const AMateria &ref): _type(ref.getType())
{
	//std::cout << "AMateria was created with copy constructor" << std::endl;
	return ;
}

AMateria	&AMateria::operator=(const AMateria &rhs)
{
	(void)rhs;
	std::cout << "copy assignment operator won't work on AMateria" << std::endl;
	return *this;
}

AMateria::~AMateria(void)
{
	//std::cout << "AMateria was destroyed" << std::endl;
	return ;
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
	return ;
}
