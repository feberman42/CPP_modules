/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:53:01 by feberman          #+#    #+#             */
/*   Updated: 2024/02/24 12:39:16 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <cstdlib>

std::string	get_input(const char *prompt);
std::string	truncate(const std::string str, long unsigned int width, const char *terminator);

#endif