/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:25:47 by feberman          #+#    #+#             */
/*   Updated: 2024/05/06 10:18:30 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat &ref);
		Cat	&operator=(const Cat &rhs);
		~Cat(void);

		void	makeSound(void) const;
	private:
};

std::ostream	&operator<<(std::ostream &os, Cat const &c);

#endif
