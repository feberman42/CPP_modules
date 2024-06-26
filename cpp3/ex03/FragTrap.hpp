/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:11:37 by feberman          #+#    #+#             */
/*   Updated: 2024/05/03 11:45:15 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &ref);
		FragTrap	&operator=(const FragTrap &rhs);
		~FragTrap(void);

		void	highFive(void);

	protected:
		static const unsigned int	_defaultHitPoints = 100;
		static const unsigned int	_defaultEnergyPoints = 100;
		static const unsigned int	_defaultAttackDamage = 30;
};

std::ostream	&operator<<(std::ostream &os, FragTrap const &c);

#endif
