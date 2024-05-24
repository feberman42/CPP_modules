/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:53:44 by feberman          #+#    #+#             */
/*   Updated: 2024/05/24 12:01:13 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat	freddy("Freddy", 2);
	Bureaucrat	bob("Bob", 140);
	ShrubberyCreationForm	form("test");
	RobotomyRequestForm		form2("Max");
	
	freddy.executeForm(form);
	bob.signForm(form);
	freddy.signForm(form);
	bob.executeForm(form);
	freddy.executeForm(form);
	freddy.signForm(form2);
	freddy.executeForm(form2);
}
