/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:17:18 by feberman          #+#    #+#             */
/*   Updated: 2024/07/09 19:40:04 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	&min(T &a, T &b)
{
	return (a<b ? a : b);
}

template<typename T>
T	&max(T &a, T &b)
{
	return (a>b ? a : b);
}

#endif
