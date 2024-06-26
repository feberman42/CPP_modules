/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:01:29 by feberman          #+#    #+#             */
/*   Updated: 2024/02/25 12:52:01 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	new_entry(void);
		void	print_contacts(void) const;
		void	print_contact(int index) const;
		
	private:
		Contact	contacts[8];
		int		active;

		void	next_entry(void);

};

std::ostream	&operator<<(std::ostream &os, PhoneBook const &c);

#endif
