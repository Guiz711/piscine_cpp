/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:17:49 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/07 16:45:24 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string	Contact::TruncateEntry(std::string entry)
{
	entry[9] = '.';
	entry.resize(10);
	return entry;
}

void	Contact::SetFirstName(std::string str) { this->_FName = str; }
void	Contact::SetLastName(std::string str) { this->_LName = str; }
void	Contact::SetNickname(std::string str) { this->_Nickname = str; }
void	Contact::SetLogin(std::string str) { this->_Login = str; }
void	Contact::SetPostalAddress(std::string str) { this->_Postal = str; }
void	Contact::SetEmailAddress(std::string str) { this->_Email = str; }
void	Contact::SetPhoneNumber(std::string str) { this->_Phone = str; }
void	Contact::SetBirthday(std::string str) { this->_BDay = str; }
void	Contact::SetFavoriteMeal(std::string str) { this->_FavMeal = str; }
void	Contact::SetUnderwearColor(std::string str) { this->_UnderwearCol = str; }
void	Contact::SetDarkestSecret(std::string str) { this->_Secret = str; }

std::string	Contact::GetFirstName(bool truncate) const
{
	if (!truncate || this->_FName.length() <= 10)
		return this->_FName;
	return Contact::TruncateEntry(this->_FName);
}

std::string	Contact::GetLastName(bool truncate) const
{
	if (!truncate || this->_LName.length() <= 10)
		return this->_LName;
	return Contact::TruncateEntry(this->_LName);
}

std::string	Contact::GetNickname(bool truncate) const
{
	if (!truncate || this->_Nickname.length() <= 10)
		return this->_Nickname;
	return Contact::TruncateEntry(this->_Nickname);
}

std::string	Contact::GetLogin(void) const { return this->_Login; }
std::string	Contact::GetPostalAddress(void) const { return this->_Postal; }
std::string	Contact::GetEmailAddress(void) const { return this->_Email; }
std::string	Contact::GetPhoneNumber(void) const { return this->_Phone; }
std::string	Contact::GetBirthday(void) const { return this->_BDay; }
std::string	Contact::GetFavoriteMeal(void) const { return this->_FavMeal; }
std::string	Contact::GetUnderwearColor(void) const { return this->_UnderwearCol; }
std::string	Contact::GetDarkestSecret(void) const { return this->_Secret; }