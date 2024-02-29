/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:32:25 by feberman          #+#    #+#             */
/*   Updated: 2024/02/29 16:41:37 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	read_file(std::ifstream &file_stream, std::string &buffer)
{
	char			buf[100];

	while (file_stream.getline(buf, 100).eof() == false)
	{
		buffer.append(buf);
		buffer.push_back('\n');
	}
	buffer.append(buf);
	return ;
}

int	replace(std::string &str, std::string const s1, std::string const s2)
{
	size_t	index;

	if (s2.find(s1) != s2.npos)
		return (print_error(ERR_LOOP, 1));
	index = str.find(s1);
	while (index != str.npos)
	{
		str.erase(index, s1.length());
		str.insert(index, s2);
		index = str.find(s1);
	}
	return (0);
}

void	write_to_file(std::string name, std::string const &str)
{
	std::ofstream	file;

	name.append(".replace");
	file.open(name.c_str(), std::ofstream::trunc);
	if (file.is_open() == false)
	{
		print_error(ERR_OUTFILE, 1);
		return ;
	}
	file << str;
	file.close();
	return ;
}
