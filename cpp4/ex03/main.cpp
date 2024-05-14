/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:24:03 by feberman          #+#    #+#             */
/*   Updated: 2024/05/07 14:45:45 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character();
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		Character		freddy("freddy");
		Character		froddy("froddy");
		MateriaSource	src;
		AMateria		*tmp[4];

		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		tmp[0] = src.createMateria("ice");
		tmp[1] = src.createMateria("cure");
		freddy.equip(tmp[0]);
		freddy.equip(tmp[1]);
		freddy.use(0, froddy);
		froddy = freddy;
		froddy.use(1, freddy);
		freddy.unequip(1);
		freddy.use(1, froddy);
		delete (tmp[1]);
		froddy.use(1, freddy);
	}
	return 0;
}
