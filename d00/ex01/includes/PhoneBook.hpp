/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:44:49 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/07 16:49:15 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

class PhoneBook
{
	public:
		static const int	MaxContacts;
	
		PhoneBook(void);
		~PhoneBook(void);

		void	StartPrompt(void);

	private:
		Contact	*_Contacts;
		int		_ContactsQuantity;
		int		_AddContactIndex;

		void	AddContact(void);
		void	SearchContacts(void);
		void	ShowContact(int index);
};

#endif