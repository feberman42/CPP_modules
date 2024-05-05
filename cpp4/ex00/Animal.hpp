/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:16:09 by feberman          #+#    #+#             */
/*   Updated: 2024/05/05 14:14:37 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &ref);
		Animal	&operator=(const Animal &rhs);
		virtual	~Animal(void);

		void					setType(const std::string &type);
		const std::string	&getType(void) const;

		virtual void	makeSound(void) const;
	protected:
		std::string	_type;
};

std::ostream	&operator<<(std::ostream &os, Animal const &c);

#endif
