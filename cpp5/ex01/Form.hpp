/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:56:32 by feberman          #+#    #+#             */
/*   Updated: 2024/06/04 09:29:31 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string &name, int signGrade, int execGrade);
		Form(const Form &ref);
		~Form(void);

		const std::string	&getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

		void	beSigned(Bureaucrat &b);

	private:
		Form(void);
		Form	&operator=(const Form &rhs);
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		void				checkGrade(void) const;

		class GradeTooHighException: public std::exception {};
		class GradeTooLowException: public std::exception {};
};

std::ostream	&operator<<(std::ostream &os, Form const &c);

#endif
