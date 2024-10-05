/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:25:38 by feberman          #+#    #+#             */
/*   Updated: 2024/10/05 13:02:05 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iomanip>
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

		template<typename T>
		void	addNumber(T start, T end)
		{
			while (start != end)
			{
				try
				{
					this->addNumber(*start);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					return ;
				}
				++start;
			}
			return ;
		}
	
	private:
		Span(void);

		std::vector<int>	_nums;
		unsigned int		_size;

		class SizeException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class SpanException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, Span const &c);

#endif
