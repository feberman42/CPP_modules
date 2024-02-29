/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:24:11 by feberman          #+#    #+#             */
/*   Updated: 2024/02/29 11:28:36 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	print_error(const char *err_msg, int code)
{
	std::cerr << err_msg << std::endl;
	return (code);
}
