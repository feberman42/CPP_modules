/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:33:54 by feberman          #+#    #+#             */
/*   Updated: 2024/07/09 19:50:41 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <stddef.h>
# include <iostream>

template<typename T>
void	printValue(T &value)
{
	std::cout << value << std::endl;
	return ;
}

template<typename T>
void	iter(T *arr, size_t len, void(*func)(T&))
{
	if(arr == NULL)
		return ;
	for(size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
	return ;
}

#endif
