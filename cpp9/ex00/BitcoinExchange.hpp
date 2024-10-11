/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:43:28 by feberman          #+#    #+#             */
/*   Updated: 2024/10/11 17:34:57 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <cstdlib>

# define FAIL 1
# define SUCCESS 0

class BitcoinExchange
{
	public:
		BitcoinExchange(const char *path);
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange	&operator=(const BitcoinExchange &rhs);
		~BitcoinExchange(void);

	private:
		BitcoinExchange(void);
		std::map<std::string, float>	_data;

		class InvalidInputData: public std::exception
		{
			const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, BitcoinExchange const &c);

#endif
