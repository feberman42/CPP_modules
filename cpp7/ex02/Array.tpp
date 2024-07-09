/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:04:32 by feberman          #+#    #+#             */
/*   Updated: 2024/07/09 20:52:50 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(void): _size(0)
{
	this->_arr = NULL;
	return ;
}

template<typename T>
Array<T>::Array(unsigned int size): _size(size)
{
	this->_arr = new T[size];
	return ;
}

template<typename T>
Array<T>::Array(const Array &ref): _size(0)
{
	this->_arr = NULL;
	*this = ref;
	return ;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &rhs)
{
	if (this->_arr != NULL)
		delete[](this->_arr);
	this->_size = rhs.size();
	this->_arr = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		(*this)[i] = rhs[i];
	return *this;
}

template<typename T>
Array<T>::~Array(void)
{
	delete[](this->_arr);
	return ;
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template<typename T>
T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw Array<T>::IndexException();
	return (this->_arr[index]);
}

template<typename T>
const char	*Array<T>::IndexException::what(void) const throw()
{
	return ("Index out of range.");
}
