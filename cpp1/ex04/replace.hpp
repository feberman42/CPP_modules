/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:24:42 by feberman          #+#    #+#             */
/*   Updated: 2024/02/29 16:37:15 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <fstream>
# include <iostream>
# include <string>

# define ERR_ARGS "Wong number of arguments"
# define ERR_INFILE "Could not open infile"
# define ERR_OUTFILE "Could not create outfile"
# define ERR_LOOP "Infinite replacement loop detected"

int		print_error(const char *err_msg, int code);
void	read_file(std::ifstream &file_stream, std::string &buffer);
int		replace(std::string &str, std::string const s1, std::string const s2);
void	write_to_file(std::string name, std::string const &str);

#endif
