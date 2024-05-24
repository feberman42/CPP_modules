/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:49:19 by feberman          #+#    #+#             */
/*   Updated: 2024/05/24 11:36:38 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
AForm("ShrubberyCreation", 145, 137), _target("default")
{
	//std::cout << "ShrubberyCreationForm was created" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
AForm("ShrubberyCreation", 145, 137), _target(target)
{
	//std::cout << "ShrubberyCreationForm was created" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref):
AForm("ShrubberyCreation", 145, 137), _target(ref._target)
{
	std::cout << "ShrubberyCreationForm was created with copy constructor" << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	rhs.getName();
	//std::cout << "copy assignment operator called on ShrubberyCreationForm" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	//std::cout << "ShrubberyCreationForm was destroyed" << std::endl;
	return ;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	out;

	try
	{
		this->checkExecute(executor.getGrade());
	}
	catch (const AForm::FormNotSigned &e)
	{
		std::cerr << this->getName() << " with target: \"" << this->_target << "\" is not signed." << std::endl;
		return ;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << executor.getName() << "'s grade is too low to execute " << this->getName() << std::endl;
		return ;
	}

	out.open((this->_target + "_shrubbery").c_str());
	if (out.is_open() == false)
	{
		std::cerr << "Problem with shrubbery output file." << std::endl;
		return ;
	}
	ShrubberyCreationForm::putShrubbery(out);
	out.close();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	return ;
}

void	ShrubberyCreationForm::putShrubbery(std::ofstream &file)
{
	file << "               ,@@@@@@@,                 " << std::endl <<
			"       ,,,.   ,@@@@@@/@@,  .oo8888o.     " << std::endl <<
			"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    " << std::endl <<
			"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   " << std::endl <<
			"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   " << std::endl <<
			"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'    " << std::endl <<
			"   `&%\\ ` /%&'    |.|        \\ '|8'      " << std::endl <<
			"       |o|        | |         | |        " << std::endl <<
			"       |.|        | |         | |        " << std::endl <<
			"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
}


