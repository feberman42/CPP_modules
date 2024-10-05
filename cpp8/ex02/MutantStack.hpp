/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:46:15 by feberman          #+#    #+#             */
/*   Updated: 2024/10/05 14:30:09 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &ref);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin(void);
		iterator	end(void);

	private:
		
};

# include "MutantStack.tpp"

#endif
