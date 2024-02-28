/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:01:14 by feberman          #+#    #+#             */
/*   Updated: 2024/02/28 13:47:18 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>


class Zombie
{
	public:
	
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
		void	set_name(std::string name);
	
	private:

		std::string	_name;
		
};

std::ostream	&operator<<(std::ostream &os, Zombie const &c);

Zombie	*zombieHorde(int N, std::string name);

#endif
