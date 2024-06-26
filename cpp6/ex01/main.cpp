/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:49:05 by feberman          #+#    #+#             */
/*   Updated: 2024/06/26 10:09:08 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data		data;
	Data		*deserialized;
	uintptr_t	ptr;

	data.setMyInt(321);
	data.setMyString("I love 42!");
	std::cout << &data << std::endl << data;
	ptr = Serializer::serialize(&data);
	std::cout << "Serialized pointer: " << ptr << std::endl;
	deserialized = Serializer::deserialize(ptr);
	std::cout << deserialized << std::endl;
	std::cout << *deserialized;
}
