/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:40:16 by feberman          #+#    #+#             */
/*   Updated: 2024/05/07 12:45:23 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &ref);
		MateriaSource	&operator=(const MateriaSource &rhs);
		~MateriaSource(void);

		void		learnMateria(AMateria *);
		AMateria	*createMateria(std::string const &type);
	private:
		AMateria	*_inventory[4];
};

#endif
