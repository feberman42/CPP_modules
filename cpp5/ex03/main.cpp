/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:53:44 by feberman          #+#    #+#             */
/*   Updated: 2024/06/04 09:20:19 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern		intern;
	Bureaucrat	freddy("freddy", 1);
	AForm		*form;

	form = intern.makeForm("shrubbery", "earth");
	freddy.signForm(*form);
	freddy.executeForm(*form);
	delete form;
	form = intern.makeForm("presidental pardon", "freddy");
	freddy.signForm(*form);
	freddy.executeForm(*form);
	delete form;
}
