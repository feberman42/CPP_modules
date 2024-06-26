/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:17:48 by feberman          #+#    #+#             */
/*   Updated: 2024/06/26 10:03:34 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	public:
		Data(void);
		~Data(void);

		int					getMyInt(void) const;
		const std::string	getMyString(void) const;
		void				setMyInt(int value);
		void				setMyString(const std::string &value);

	private:
		Data(const Data &ref);
		Data	&operator=(const Data &rhs);

		int			_myInt;
		std::string	_myString;
};

std::ostream	&operator<<(std::ostream &os, Data const &c);

#endif
