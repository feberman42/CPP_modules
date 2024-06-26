/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:35:38 by feberman          #+#    #+#             */
/*   Updated: 2024/06/26 15:06:28 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>

Base	*generate(void)
{
	int	class_id;

	srand(time(NULL));
	class_id = rand() % 3;
	switch (class_id)
	{
	case 0:
		return (static_cast<Base *>(new A));
		break;
	case 1:
		return (static_cast<Base *>(new B));
		break;
	case 2:
		return (static_cast<Base *>(new C));
		break;
	default:
		break;
	}
	return (NULL);
}

void	identify(Base *p)
{
	A	*a_test;
	B	*b_test;
	C	*c_test;

	a_test = dynamic_cast<A *>(p);
	b_test = dynamic_cast<B *>(p);
	c_test = dynamic_cast<C *>(p);
	if (a_test != NULL)
		std::cout << "A" << std::endl;
	else if (b_test != NULL)
		std::cout << "B" << std::endl;
	else if (c_test != NULL)
		std::cout << "C" << std::endl;
	return ;
}

int main(void)
{
	Base	*ptr = NULL;

	ptr = generate();
	identify(ptr);
	if (ptr != NULL)
		delete (ptr);
	return (0);
}
