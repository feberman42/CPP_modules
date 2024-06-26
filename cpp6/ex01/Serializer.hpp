/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:13:28 by feberman          #+#    #+#             */
/*   Updated: 2024/06/26 10:05:32 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"
# include <stdint.h>

class Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
	private:
		Serializer(const Serializer &ref);
		Serializer(void);
		Serializer	&operator=(const Serializer &rhs);
		~Serializer(void);
};

#endif
