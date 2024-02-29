/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:05:11 by feberman          #+#    #+#             */
/*   Updated: 2024/02/29 16:41:24 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char **argv)
{
	std::ifstream	input;
	std::string		file_string;

	if (argc != 4)
		return (print_error(ERR_ARGS, 1));
	input.open(argv[1]);
	if (input.is_open() == false)
		return (print_error(ERR_INFILE, 2));
	read_file(input, file_string);
	input.close();
	if (replace(file_string, argv[2], argv[3]) == 0)
		write_to_file(argv[1], file_string);
	return (0);
}
