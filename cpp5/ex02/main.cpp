/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:53:44 by feberman          #+#    #+#             */
/*   Updated: 2024/06/04 09:32:39 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

int	main(void)
{
	Bureaucrat	freddy("Freddy", 2);
	Bureaucrat	bob("Bob", 140);
	ShrubberyCreationForm	form("test");
	RobotomyRequestForm		form2("Max");
	PresidentalPardonForm	form3("Kars");

	try
	{
		freddy.executeForm(form);
		freddy.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		bob.signForm(form2);
		freddy.executeForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		freddy.signForm(form3);
		freddy.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
