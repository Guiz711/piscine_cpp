/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:45:58 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 20:13:13 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

/*
** Constructors and destructor
*/

Sorcerer::Sorcerer(void) {}

Sorcerer::Sorcerer(const std::string& name, const std::string& title):
	_Name(name),
	_Title(title)
{
	std::cout << this->_Name << ", " << this->_Title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer& src):
	_Name(src.getName()),
	_Title(src.getTitle())
{
	std::cout << this->_Name << ", " << this->_Title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_Name << ", " << this->_Title
		<< ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer&	Sorcerer::operator=(const Sorcerer& rhs)
{
	if (this == &rhs)
		return *this;

	this->_Name = rhs.getName();
	this->_Title = rhs.getTitle();
	
	return *this;
}

/*
** Public member functions
*/

void				Sorcerer::polymorph(const Victim& victim) const
{
	victim.getPolymorphed();
}


const std::string&	Sorcerer::getName(void) const { return this->_Name; }
const std::string&	Sorcerer::getTitle(void) const { return this->_Title; }

std::ostream&	operator<<(std::ostream& lfs, const Sorcerer& rhs)
{
	lfs << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return lfs;
}
