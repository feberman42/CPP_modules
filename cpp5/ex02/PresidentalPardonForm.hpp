/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:42:01 by feberman          #+#    #+#             */
/*   Updated: 2024/05/24 13:18:07 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentalPardonForm: public AForm
{
	public:
		PresidentalPardonForm(const std::string &target);
		PresidentalPardonForm(const PresidentalPardonForm &ref);
		~PresidentalPardonForm(void);

		void	execute(const Bureaucrat &executor) const;
	private:
		PresidentalPardonForm(void);
		PresidentalPardonForm	&operator=(const PresidentalPardonForm &rhs);
};

#endif
