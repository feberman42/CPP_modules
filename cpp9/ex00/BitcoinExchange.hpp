/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:43:28 by feberman          #+#    #+#             */
/*   Updated: 2024/10/17 21:48:15 by feberman         ###   ########.fr       */
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
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange	&operator=(const BitcoinExchange &rhs);
		~BitcoinExchange(void);

		void	calculate(const char *path) const;

	private:
		bool	loadFile(const char *path);
		void	dbLookup(std::string &line) const;
		
		std::map<std::string, float>	_data;
};

#endif
