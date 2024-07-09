/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:30:20 by feberman          #+#    #+#             */
/*   Updated: 2024/06/04 09:29:31 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	this->checkGrade();
	std::cout << "Bureaucrat: " << name << " was created with grade " << grade << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name(ref._name)
{
	std::cout << "Bureaucrat: " << ref._name << " was copied." << std::endl;
	*this = ref;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat : " << this->_name << " went home." << std::endl;
	return ;
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::increment(void)
{
	this->_grade--;
	this->checkGrade();
	return ;
}

void	Bureaucrat::decrement(void)
{
	this->_grade++;
	this->checkGrade();
	return ;
}

void	Bureaucrat::checkGrade(void)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &c)
{
	os << c.getName() << " bureaucrat grade " << c.getGrade();
	return (os);
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade of bureaucrat was raised above 1.");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade of bureaucrat was decreses below 150.");
}
