/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:23:54 by feberman          #+#    #+#             */
/*   Updated: 2024/05/24 11:24:31 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &ref);
		Bureaucrat	&operator=(const Bureaucrat &rhs);
		~Bureaucrat(void);

		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				increment(void);
		void				decrement(void);

		void	signForm(AForm &f) const;
		void	executeForm(const AForm &f) const;

	private:
		Bureaucrat(void);
		const std::string	_name;
		int					_grade;
		void				checkGrade(void);

		class GradeTooHightException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &c);

#endif
