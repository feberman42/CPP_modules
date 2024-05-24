/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:46:41 by feberman          #+#    #+#             */
/*   Updated: 2024/05/24 13:16:46 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
AForm("RobotomyRequest", 72, 45)
{
	this->_target = "default";
	//std::cout << "RobotomyRequestForm was created" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
AForm("RobotomyRequest", 72, 45)
{
	this->_target = target;
	//std::cout << "RobotomyRequestForm was created" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref):
AForm("RobotomyRequest", 72, 45)
{
	this->_target = ref._target;
	//std::cout << "RobotomyRequestForm was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	rhs.getName();
	//std::cout << "copy assignment operator called on RobotomyRequestForm" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	//std::cout << "RobotomyRequestForm was destroyed" << std::endl;
	return ;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkExecute(executor.getGrade());

	std::cout << "* DRILLING NOISES *" << std::endl;
	std::cout << "Robotomy of " << this->_target;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << " was successful." << std::endl;
	else
		std::cout << " failed." << std::endl;
	return ;
}
