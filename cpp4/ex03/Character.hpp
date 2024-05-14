/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:11:06 by feberman          #+#    #+#             */
/*   Updated: 2024/05/07 14:21:16 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

// class AMateria;

class Character: public ICharacter
{
	public:
		Character(void);
		Character(const Character &ref);
		Character(const std::string &name);
		Character	&operator=(const Character &rhs);
		~Character(void);

		std::string const	&getName(void) const;

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);
	private:
		const std::string	_name;
		AMateria			*_inventory[4];
};

#endif
