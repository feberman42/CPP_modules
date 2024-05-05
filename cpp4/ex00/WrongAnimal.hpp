/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:56:24 by feberman          #+#    #+#             */
/*   Updated: 2024/05/05 14:14:30 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &ref);
		WrongAnimal	&operator=(const WrongAnimal &rhs);
		virtual	~WrongAnimal(void);

		void				setType(const std::string &type);
		const std::string	&getType(void) const;
		
		void	makeSound(void) const;

	protected:
		std::string	_type;
};

std::ostream	&operator<<(std::ostream &os, WrongAnimal const &c);

#endif
