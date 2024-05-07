/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:31:57 by feberman          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:41 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// AAnimal	peter;
	{
		const AAnimal	*j = new Dog();
		const AAnimal	*i = new Cat();

		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		AAnimal			*animals[12];
		unsigned int	i;

		i = 0;
		for (i = 0; i < 12; i++)
		{
			if (i < 6)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		for (i = 0; i < 12; i++)
			animals[i]->makeSound();
		for (i = 0; i < 12; i++)
			delete animals[i];
	}
	std::cout << std::endl;
	{
		Cat	orig;
		Cat	copy(orig);
		Dog	origDog;
		Dog	copyDog(origDog);

		std::cout << "Original cat brain:\t" << orig.getBrain() << std::endl;
		std::cout << "Copied cat brain:\t" << copy.getBrain() << std::endl;
		std::cout << "Original dog brain:\t" << origDog.getBrain() << std::endl;
		std::cout << "Copied dog brain:\t" << copyDog.getBrain() << std::endl;

		orig.getBrain()->newIdea("I am hungry");
		orig.getBrain()->newIdea("I hate humanity");
		orig.getBrain()->printIdeas();
	}
	return (0);
}
