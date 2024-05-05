/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:28:54 by feberman          #+#    #+#             */
/*   Updated: 2024/05/05 13:29:37 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog &ref);
		Dog	&operator=(const Dog &rhs);
		~Dog(void);

		void	makeSound(void) const;
	private:
		
};

std::ostream	&operator<<(std::ostream &os, Dog const &c);

#endif
