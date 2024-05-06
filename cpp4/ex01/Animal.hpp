/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:16:09 by feberman          #+#    #+#             */
/*   Updated: 2024/05/06 10:42:01 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &ref);
		Animal	&operator=(const Animal &rhs);
		virtual	~Animal(void);

		void					setType(const std::string &type);
		const std::string	&getType(void) const;
		Brain				*getBrain(void) const;

		virtual void	makeSound(void) const;
	protected:
		std::string	_type;
		Brain		*_brain;

};

std::ostream	&operator<<(std::ostream &os, Animal const &c);

#endif
