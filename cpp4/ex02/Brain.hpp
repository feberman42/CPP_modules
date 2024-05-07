/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:59:22 by feberman          #+#    #+#             */
/*   Updated: 2024/05/06 10:11:39 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &ref);
		Brain	&operator=(const Brain &rhs);
		~Brain(void);

		void	newIdea(const std::string &idea);
		void	printIdeas(void) const;

	private:
		std::string		_ideas[100];
		unsigned int	_index;
};

#endif
