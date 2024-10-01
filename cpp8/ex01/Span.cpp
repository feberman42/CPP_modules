/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:16:11 by feberman          #+#    #+#             */
/*   Updated: 2024/09/18 16:53:45 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): _size(N)
{
	std::cout << "Span of size " << _size << " was created" << std::endl;
	return ;
}

Span::Span(const Span &ref)
{
	//std::cout << "Span was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

Span	&Span::operator=(const Span &rhs)
{
	//std::cout << "copy assignment operator called on Span" << std::endl;
	this->_size = rhs._size;
	this->_nums.clear();
	for (size_t i = 0; i < rhs._nums.size(); ++i)
	{
		_nums.push_back(rhs._nums[i]);
	}
	return *this;
}

Span::~Span(void)
{
	//std::cout << "Span was destroyed" << std::endl;
	return ;
}

unsigned int	Span::getSize(void) const { return (_size); }

std::vector<int>	&Span::getNums(void) const { return (const_cast<std::vector<int> &>(_nums)); }

void	Span::addNumber(int num)
{
	if (_nums.size() >= _size)
		throw std::exception();
	
	_nums.push_back(num);
}

unsigned int	Span::shortestSpan(void) const
{
	// NEED TO IMPLEMENT
	return (0);
}

unsigned int	Span::longestSpan(void) const
{
	// NEED TO IMPLEMENT
	return (0);
}

std::ostream	&operator<<(std::ostream &os, Span const &c)
{
	std::vector<int>	&nums = c.getNums();

	os << "Span of size: " << c.getSize() << std::endl;
	for (unsigned int i = 0; i < nums.size(); ++i)
	{
		os << nums[i];
		if (i % 10 == 9)
			os << std::endl;
		else
			os << " ";
	}
	os << std::endl;
	return (os);
}
