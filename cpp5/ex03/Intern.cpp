/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:00:30 by feberman          #+#    #+#             */
/*   Updated: 2024/06/04 09:20:50 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	//std::cout << "Intern was created" << std::endl;
	return ;
}

Intern::Intern(const Intern &ref)
{
	(void)ref;
	//std::cout << "Intern was created with copy constructor" << std::endl;
	return ;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	//std::cout << "copy assignment operator called on Intern" << std::endl;
	return *this;
}

Intern::~Intern(void)
{
	//std::cout << "Intern was destroyed" << std::endl;
	return ;
}

static AForm	*newShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*newRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*newPresidentalPardon(const std::string &target)
{
	return (new PresidentalPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	AForm *(*funcs[3])(const std::string &target) = {&newShrubbery, &newRobotomy, &newPresidentalPardon};
	const char	*names[3] = {"shrubbery", "robotomy request", "presidental pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (funcs[i](target));
		}
	}
	std::cout << "Intern is useless. They dont know what a " << name << " is..." << std::endl;
	return (NULL);
}
