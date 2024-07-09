/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:05:52 by feberman          #+#    #+#             */
/*   Updated: 2024/05/23 18:10:49 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void):
_name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	return ;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade):
_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	this->checkGrade();
	std::cout << "AForm: " << name << " was created " << signGrade << "/" << execGrade << std::endl;
	return ;
}

AForm::AForm(const AForm &ref):
_name(ref._name), _signed(ref._signed), _signGrade(ref._signGrade), _execGrade(ref._execGrade)
{
	std::cout << "AForm " << ref._name << "was copied." << std::endl;
	return ;
}

AForm	&AForm::operator=(const AForm &rhs)
{
	//std::cout << "copy assignment operator called on AForm" << std::endl;
	rhs.getName();
	return *this;
}

AForm::~AForm(void)
{
	std::cout << "AForm: " << this->_name << " was destroyed." << std::endl;
	return ;
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

const std::string	&AForm::getTarget(void) const
{
	return (this->_target);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	AForm::checkGrade(void) const
{
	if (this->_execGrade < 1 || this->_signGrade < 1)
		throw (AForm::GradeTooHighException());
	if (this->_execGrade > 150 || this->_signGrade > 150)
		throw (AForm::GradeTooLowException());
	return ;
}

void	AForm::checkExecute(int grade) const
{
	if (this->_signed == false)
		throw (AForm::FormNotSigned(*this));
	if (this->_execGrade < grade)
		throw (AForm::GradeTooLowException());
	return ;
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw (AForm::GradeTooLowException());
	return ;
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

AForm::FormNotSigned::FormNotSigned(const AForm &form):
_form(form)
{
	this->msg = std::string(this->_form.getName() + " with target: \"" + this->_form._target + "\" is not signed.");
}

AForm::FormNotSigned::~FormNotSigned(void) throw()
{
	return ;
}

const char	*AForm::FormNotSigned::what(void) const throw()
{
	return (this->msg.c_str());
}

std::ostream	&operator<<(std::ostream &os, AForm const &c)
{
	if (c.getSigned())
		os << "Signed ";
	else
		os << "Unsigned ";
	os << "AForm: " << c.getName() << "(" << c.getSignGrade() << "/" << c.getExecGrade() << ")";
	return (os);
}
