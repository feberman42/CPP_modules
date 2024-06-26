/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:55:14 by feberman          #+#    #+#             */
/*   Updated: 2024/06/20 15:41:50 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>

class ScalarConverter
{
	public:
		static void	convert(const std::string &input);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter	&operator=(const ScalarConverter &rhs);
		~ScalarConverter(void);
		
};

#endif
