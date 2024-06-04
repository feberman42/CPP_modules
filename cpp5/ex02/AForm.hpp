/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:56:32 by feberman          #+#    #+#             */
/*   Updated: 2024/05/23 18:10:38 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm(const AForm &ref);
		virtual ~AForm(void);

		const std::string	&getName(void) const;
		const std::string	&getTarget(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

		void			beSigned(Bureaucrat &b);
		virtual void	execute(Bureaucrat const &executor) const = 0;

	protected:
		std::string			_target;
		void				checkExecute(int grade) const;

		class GradeTooHighException: public std::exception
		{
			const char	*what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			const char	*what(void) const throw();
		};

		class FormNotSigned: public std::exception
		{
			public:
				FormNotSigned(const AForm &form);
				~FormNotSigned(void) throw();
				const char	*what(void) const throw();
			private:
				const AForm	&_form;
				std::string	msg;
		};

	private:
		AForm(void);
		AForm	&operator=(const AForm &rhs);
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		void				checkGrade(void) const;
};

std::ostream	&operator<<(std::ostream &os, AForm const &c);

#endif
