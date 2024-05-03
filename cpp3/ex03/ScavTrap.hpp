/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:21:26 by feberman          #+#    #+#             */
/*   Updated: 2024/05/03 11:45:27 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &ref);
		ScavTrap	&operator=(const ScavTrap &rhs);
		~ScavTrap(void);

		void	attack(const std::string &target);
		void	guardGate(void);

	protected:
		static const unsigned int	_defaultHitPoints = 100;
		static const unsigned int	_defaultEnergyPoints = 50;
		static const unsigned int	_defaultAttackDamage = 20;
};

std::ostream	&operator<<(std::ostream &os, ScavTrap const &c);

#endif
