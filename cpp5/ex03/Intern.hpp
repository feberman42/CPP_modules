/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:56:33 by feberman          #+#    #+#             */
/*   Updated: 2024/05/24 21:53:55 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentalPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &ref);
		Intern	&operator=(const Intern &rhs);
		~Intern(void);

		AForm	*makeForm(const std::string &name, const std::string &target) const;
};

#endif
