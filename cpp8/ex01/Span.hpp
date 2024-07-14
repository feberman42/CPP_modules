/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:25:38 by feberman          #+#    #+#             */
/*   Updated: 2024/07/14 19:14:24 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &ref);
		Span	&operator=(const Span &rhs);
		~Span(void);

		void	addNumber(int num);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

	private:
		Span(void);
		
};

std::ostream	&operator<<(std::ostream &os, Span const &c);

#endif
