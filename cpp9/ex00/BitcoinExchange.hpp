/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:43:28 by feberman          #+#    #+#             */
/*   Updated: 2024/10/05 15:48:00 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string path);
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange	&operator=(const BitcoinExchange &rhs);
		~BitcoinExchange(void);

	private:
		BitcoinExchange(void);
		std::map<std::string, float>	_data;
};

std::ostream	&operator<<(std::ostream &os, BitcoinExchange const &c);

#endif
