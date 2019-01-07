/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:56:25 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/07 17:23:07 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

const int	PhoneBook::MaxContacts = 8;

PhoneBook::PhoneBook(void) : _Contacts(new Contact[PhoneBook::MaxContacts]), _ContactsQuantity(0), _AddContactIndex(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void		PhoneBook::StartPrompt(void)
{
	std::string	userInput;

	while (1)
	{
		std::cout << BLU "Please enter a command " RESET "(EXIT, ADD, SEARCH):" << std::endl;
		std::cout << GRN "-> " RESET;
		std::getline(std::cin, userInput);
		if (userInput == "EXIT")
		{
			std::cout << std::endl << YEL "(╯°□°)╯︵ ʞooqǝɔɐℲ" RESET << std::endl << std::endl;
			break;
		}
		else if (userInput == "ADD")
			this->AddContact();
		else if (userInput == "SEARCH")
			this->SearchContacts();
	}
}

void		PhoneBook::ShowContact(int index)
{
	if (index >= 0 && index < this->_ContactsQuantity)
	{
		std::cout << GRN "|--" BLU "first name: " RESET
			<< this->_Contacts[index].GetFirstName(false)
			<< std::endl;
		std::cout << GRN "|--" BLU "last name: " RESET
			<< this->_Contacts[index].GetLastName(false)
			<< std::endl;
		std::cout << GRN "|--" BLU "nickname: " RESET
			<< this->_Contacts[index].GetNickname(false)
			<< std::endl;
		std::cout << GRN "|--" BLU "login: " RESET
			<< this->_Contacts[index].GetLogin()
			<< std::endl;
		std::cout << GRN "|--" BLU "postal address: " RESET
			<< this->_Contacts[index].GetPostalAddress()
			<< std::endl;
		std::cout << GRN "|--" BLU "email address: " RESET
			<< this->_Contacts[index].GetEmailAddress()
			<< std::endl;
		std::cout << GRN "|--" BLU "phone number: " RESET
			<< this->_Contacts[index].GetPhoneNumber()
			<< std::endl;
		std::cout << GRN "|--" BLU "birthday date: " RESET
			<< this->_Contacts[index].GetBirthday()
			<< std::endl;
		std::cout << GRN "|--" BLU "favorite meal: " RESET
			<< this->_Contacts[index].GetFavoriteMeal()
			<< std::endl;
		std::cout << GRN "|--" BLU "underwear color: " RESET
			<< this->_Contacts[index].GetUnderwearColor()
			<< std::endl;
		std::cout << GRN "|--" BLU "darkest secret: " RESET
			<< this->_Contacts[index].GetDarkestSecret()
			<< std::endl;
	}
	else
		std::cout << GRN "|--" RED "This contact does not exist (◍•﹏•)" RESET << std::endl;	
}

void		PhoneBook::SearchContacts()
{
	std::string userInput;
	long		index;
	char		*isNotNum;

	if (this->_ContactsQuantity == 0)
	{
		std::cout << RED "You have no friends ¯\\_(ツ)_/¯" RESET << std::endl;
		return;
	}

	for (int i = 0; i < this->_ContactsQuantity; ++i)
	{
		std::cout << std::setw(10) << i << '|'
			<< std::setw(10) << this->_Contacts[i].GetFirstName(true) << '|'
			<< std::setw(10) << this->_Contacts[i].GetLastName(true) << '|'
			<< std::setw(10) << this->_Contacts[i].GetNickname(true) << std::endl;
	}
	std::cout << GRN "|--" BLU "Choose a contact to display:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	index = std::strtol(userInput.c_str(), &isNotNum, 10);
	if (*isNotNum)
		std::cout << GRN "|--" RED "Please enter an index! ಠ_ಠ" RESET << std::endl;
	else
		this->ShowContact(index);
}

void		PhoneBook::AddContact(void)
{
	std::string userInput;

	std::cout << GRN "|--" BLU "first name:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetFirstName(userInput);
	std::cout << GRN "|--" BLU "last name:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetLastName(userInput);
	std::cout << GRN "|--" BLU "nickname:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetNickname(userInput);
	std::cout << GRN "|--" BLU "login:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetLogin(userInput);
	std::cout << GRN "|--" BLU "postal address:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetPostalAddress(userInput);
	std::cout << GRN "|--" BLU "email address:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetEmailAddress(userInput);
	std::cout << GRN "|--" BLU "phone number:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetPhoneNumber(userInput);
	std::cout << GRN "|--" BLU "birthday date:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetBirthday(userInput);
	std::cout << GRN "|--" BLU "favorite meal:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetFavoriteMeal(userInput);
	std::cout << GRN "|--" BLU "underwear color:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetUnderwearColor(userInput);
	std::cout << GRN "|--" BLU "darkest secret:" RESET << std::endl;
	std::cout << GRN "|--->" RESET;
	std::getline(std::cin, userInput);
	this->_Contacts[this->_AddContactIndex].SetDarkestSecret(userInput);
	if (this->_ContactsQuantity < PhoneBook::MaxContacts)
		this->_ContactsQuantity++;
	this->_AddContactIndex++;
	if (this->_AddContactIndex >= PhoneBook::MaxContacts)
		this->_AddContactIndex = 0;
}
