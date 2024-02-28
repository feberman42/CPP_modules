/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:41:22 by feberman          #+#    #+#             */
/*   Updated: 2024/02/28 13:56:14 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	horde = new (std::nothrow) Zombie[N];
	if (!horde)
		return (NULL);
	while (N-- > 0)
		horde[N].set_name(name);
	return (horde);
}
