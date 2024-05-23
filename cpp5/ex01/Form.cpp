/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:05:52 by feberman          #+#    #+#             */
/*   Updated: 2024/05/23 18:10:49 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):
_name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	return ;
}

Form::Form(const std::string &name, int signGrade, int execGrade):
_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	this->checkGrade();
	std::cout << "Form: " << name << " was created " << signGrade << "/" << execGrade << std::endl;
	return ;
}

Form::Form(const Form &ref):
_name(ref._name), _signed(ref._signed), _signGrade(ref._signGrade), _execGrade(ref._execGrade)
{
	std::cout << "Form " << ref._name << "was copied." << std::endl;
	return ;
}

Form	&Form::operator=(const Form &rhs)
{
	//std::cout << "copy assignment operator called on Form" << std::endl;
	rhs.getName();
	return *this;
}

Form::~Form(void)
{
	std::cout << "Form: " << this->_name << " was destroyed." << std::endl;
	return ;
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	Form::checkGrade(void) const
{
	if (this->_execGrade < 1 || this->_signGrade < 1)
		throw (Form::GradeTooHightException());
	if (this->_execGrade > 150 || this->_signGrade > 150)
		throw (Form::GradeTooLowException());
	return ;
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw (Form::GradeTooLowException());
	return ;
}


std::ostream	&operator<<(std::ostream &os, Form const &c)
{
	if (c.getSigned())
		os << "Signed ";
	else
		os << "Unsigned ";
	os << "Form: " << c.getName() << "(" << c.getSignGrade() << "/" << c.getExecGrade() << ")";
	return (os);
}
