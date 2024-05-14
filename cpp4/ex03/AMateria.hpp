/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:43:48 by feberman          #+#    #+#             */
/*   Updated: 2024/05/07 14:27:02 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "Character.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(const AMateria &ref);
		AMateria(const std::string &type);
		AMateria	&operator=(const AMateria &rhs);
		virtual ~AMateria(void);

		std::string const 	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	protected:
		std::string const	_type;
};

#endif
