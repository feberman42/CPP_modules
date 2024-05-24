/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:44:19 by feberman          #+#    #+#             */
/*   Updated: 2024/05/24 11:56:45 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		~RobotomyRequestForm(void);

		void	execute(const Bureaucrat &executor) const;
		
	private:
		RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);
		const std::string	_target;
		
};

#endif
