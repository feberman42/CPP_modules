/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:35 by feberman          #+#    #+#             */
/*   Updated: 2024/07/09 20:40:45 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int size);
		Array(const Array &ref);
		Array	&operator=(const Array &rhs);
		~Array(void);

		T	&operator[](unsigned int index) const;
		unsigned int	size(void) const;

		class IndexException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	private:
		T				*_arr;
		unsigned int	_size;
};

# include "Array.tpp"

#endif
