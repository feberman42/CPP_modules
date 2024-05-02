/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:21:26 by feberman          #+#    #+#             */
/*   Updated: 2024/05/02 19:10:43 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &ref);
		ScavTrap	&operator=(const ScavTrap &rhs);
		~ScavTrap(void);

		void	attack(const std::string &target);
		void	guardGate(void);
	private:
		
};

std::ostream	&operator<<(std::ostream &os, ScavTrap const &c);

#endif
