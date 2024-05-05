/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:58:58 by feberman          #+#    #+#             */
/*   Updated: 2024/05/05 13:59:36 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &ref);
		WrongCat	&operator=(const WrongCat &rhs);
		~WrongCat(void);

		void	makeSound(void) const;
	private:
		
};

std::ostream	&operator<<(std::ostream &os, WrongCat const &c);

#endif
