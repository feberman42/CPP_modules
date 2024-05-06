/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:02:36 by feberman          #+#    #+#             */
/*   Updated: 2024/05/06 10:11:08 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain was created" << std::endl;
	this->_index = 0;
	return ;
}

Brain::Brain(const Brain &ref)
{
	std::cout << "Brain was created with copy constructor" << std::endl;
	*this = ref;
	return ;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	//std::cout << "copy assignment operator called on Brain" << std::endl;
	int	i = -1;
	while (++i < 100)
		this->_ideas[i] = rhs._ideas[i];
	this->_index = rhs._index;
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain was destroyed" << std::endl;
	return ;
}

void	Brain::newIdea(const std::string &idea)
{
	this->_ideas[this->_index] = idea;
	this->_index++;
}

void	Brain::printIdeas(void) const
{
	int	i = -1;
	while (++i < 100)
	{
		if (this->_ideas[i].empty() == false)
			std::cout << this->_ideas[i] << std::endl;
	}
}
