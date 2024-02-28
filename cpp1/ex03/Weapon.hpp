/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:40:29 by feberman          #+#    #+#             */
/*   Updated: 2024/02/28 16:50:15 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);

		std::string const	&get_type(void) const;
		void				set_type(std::string type);

	private:
		Weapon(void);
		std::string	_type;
		
};

std::ostream	&operator<<(std::ostream &os, Weapon const &c);

#endif
