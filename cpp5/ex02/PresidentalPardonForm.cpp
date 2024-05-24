/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:46:44 by feberman          #+#    #+#             */
/*   Updated: 2024/05/24 13:18:07 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentalPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm(void):
AForm("PresidentalPardon", 25, 5)
{
	this->_target = "default";
	//std::cout << "PresidentalPardonForm was created" << std::endl;
	return ;
}

PresidentalPardonForm::PresidentalPardonForm(const std::string &target):
AForm("PresidentalPardon", 25, 5)
{
	this->_target = target;
	//std::cout << "PresidentalPardonForm was created" << std::endl;
	return ;
}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm &ref):
AForm("PresidentalPardon", 25, 5)
{
	this->_target = ref._target;
	//std::cout << "PresidentalPardonForm was created with copy constructor" << std::endl;
	return ;
}

PresidentalPardonForm	&PresidentalPardonForm::operator=(const PresidentalPardonForm &rhs)
{
	rhs.getName();
	//std::cout << "copy assignment operator called on PresidentalPardonForm" << std::endl;
	return *this;
}

PresidentalPardonForm::~PresidentalPardonForm(void)
{
	//std::cout << "PresidentalPardonForm was destroyed" << std::endl;
	return ;
}

void PresidentalPardonForm::execute(const Bureaucrat &executor) const
{
	checkExecute(executor.getGrade());
	std::cout << this->_target << " has beem pardoned by Zaphod Beeblebrox." << std::endl;
}
