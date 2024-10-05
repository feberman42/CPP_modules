/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:16:11 by feberman          #+#    #+#             */
/*   Updated: 2024/10/05 13:04:24 by feberman         ###   ########.fr       */
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
		this->addNumber(rhs._nums[i]);
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
	std::vector<int>::iterator	it;

	if (_nums.size() >= _size)
		throw Span::SizeException();
	
	it = std::lower_bound(_nums.begin(), _nums.end(), num);
	_nums.insert(it, num);
}

unsigned int	Span::shortestSpan(void) const
{
	unsigned int	shortest;

	if (_nums.size() < 2)
		throw Span::SpanException();
	
	shortest = _nums[1] - _nums[0];
	for (unsigned int i = 1; i < _nums.size(); ++i)
	{
		if (shortest > static_cast<unsigned int>(_nums[i] - _nums[i - 1]))
			shortest = _nums[i] - _nums[i - 1];
		if (shortest == 0)
			break ;
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void) const
{
	if (_nums.size() < 2)
		throw Span::SpanException();

	return (_nums[_nums.size() - 1] - _nums[0]);
}

std::ostream	&operator<<(std::ostream &os, Span const &c)
{
	std::vector<int>	&nums = c.getNums();

	os << "Span of size: " << c.getSize() << std::endl;
	for (unsigned int i = 0; i < nums.size(); ++i)
	{
		os << std::setw(3) << nums[i];
		if (i % 10 == 9)
			os << std::endl;
		else
			os << " ";
	}
	if (c.getSize() % 10 != 0)
		std::cout << std::endl;
	return (os);
}

const char	*Span::SizeException::what(void) const throw()
{
	return ("Span cannot take more numbers. Size attribute exceded.");
}

const char	*Span::SpanException::what(void) const throw()
{
	return ("Not enough valuies to calculate span.");
}
