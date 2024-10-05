/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:56:06 by feberman          #+#    #+#             */
/*   Updated: 2024/10/05 14:30:03 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
{
	//std::cout << "MutantStack was created" << std::endl;
	return ;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &ref): std::stack<T>(ref)
{
	//std::cout << "MutantStack was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	//std::cout << "MutantStack was destroyed" << std::endl;
	return ;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}
