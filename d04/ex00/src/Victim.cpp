/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:41:10 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 20:13:17 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

/*
** Constructors and destructor
*/

Victim::Victim(void) {}

Victim::Victim(const std::string& name):
	_Name(name)
{
	std::cout << "Some random victim called " << this->_Name << " just popped !" << std::endl;
}

Victim::Victim(const Victim& src):
	_Name(src.getName())
{
	std::cout << "Some random victim called " << this->_Name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->_Name << " just died for no apparent reason !" << std::endl;
}

Victim&	Victim::operator=(const Victim& rhs)
{
	if (this == &rhs)
		return *this;

	this->_Name = rhs.getName();
	
	return *this;
}

/*
** Public member functions
*/

void				Victim::getPolymorphed() const
{
	std::cout << this->_Name << " has been turned into a cute little sheep !" << std::endl;
}

const std::string&	Victim::getName(void) const { return this->_Name; }

std::ostream&	operator<<(std::ostream& lfs, const Victim& rhs)
{
	lfs << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return lfs;
}