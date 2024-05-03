/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:35:30 by feberman          #+#    #+#             */
/*   Updated: 2024/05/03 11:25:48 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &ref);
		DiamondTrap	&operator=(const DiamondTrap &rhs);
		~DiamondTrap(void);

		void	whoAmI(void);
	private:
		std::string	_name;
};

std::ostream	&operator<<(std::ostream &os, DiamondTrap const &c);

#endif
