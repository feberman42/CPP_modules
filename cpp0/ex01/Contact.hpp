/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:01:56 by feberman          #+#    #+#             */
/*   Updated: 2024/02/27 13:12:32 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nick_name(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_secret(void) const;

		void		set_first_name(std::string const str);
		void		set_last_name(std::string const str);
		void		set_nick_name(std::string const str);
		void		set_phone_number(std::string const str);
		void		set_secret(std::string const str);


	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	secret;
		

};

std::ostream	&operator<<(std::ostream &os, Contact const &c);

#endif
