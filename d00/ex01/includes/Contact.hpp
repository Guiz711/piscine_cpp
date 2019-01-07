/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:18:28 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/07 16:43:10 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		SetFirstName(std::string str);
		void		SetLastName(std::string str);
		void		SetNickname(std::string str);
		void		SetLogin(std::string str);
		void		SetPostalAddress(std::string str);
		void		SetEmailAddress(std::string str);
		void		SetPhoneNumber(std::string str);
		void		SetBirthday(std::string str);
		void		SetFavoriteMeal(std::string str);
		void		SetUnderwearColor(std::string str);
		void		SetDarkestSecret(std::string str);

		std::string	GetFirstName(bool truncate) const;
		std::string	GetLastName(bool truncate) const;
		std::string	GetNickname(bool truncate) const;
		std::string	GetLogin(void) const;
		std::string	GetPostalAddress(void) const;
		std::string	GetEmailAddress(void) const;
		std::string	GetPhoneNumber(void) const;
		std::string	GetBirthday(void) const;
		std::string	GetFavoriteMeal(void) const;
		std::string	GetUnderwearColor(void) const;
		std::string	GetDarkestSecret(void) const;

	private:
		std::string _FName;
		std::string _LName;
		std::string _Nickname;
		std::string _Login;
		std::string _Postal;
		std::string _Email;
		std::string _Phone;
		std::string _BDay;
		std::string _FavMeal;
		std::string _UnderwearCol;
		std::string _Secret;

		static std::string	TruncateEntry(std::string entry);
};

#endif
