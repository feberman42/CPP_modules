/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:25:38 by feberman          #+#    #+#             */
/*   Updated: 2024/09/18 16:08:54 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &ref);
		Span	&operator=(const Span &rhs);
		~Span(void);

		void				addNumber(int num);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;
		unsigned int		getSize(void) const;
		std::vector<int>	&getNums(void) const;

	private:
		Span(void);

		std::vector<int>	_nums;
		unsigned int		_size;
};

std::ostream	&operator<<(std::ostream &os, Span const &c);

#endif
