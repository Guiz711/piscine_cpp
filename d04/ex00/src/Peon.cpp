/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:52:07 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 20:13:31 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

/*
** Constructors and destructor
*/

Peon::Peon(void) {}

Peon::Peon(const std::string& name):
	Victim(name)
{
	std::cout << "Zog zog" << std::endl;
}

Peon::Peon(const Peon& src):
	Victim(src)
{
	std::cout << "Zog zog" << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon&	Peon::operator=(const Peon& rhs)
{
	if (this == &rhs)
		return *this;

	this->_Name = rhs.getName();
	
	return *this;
}

/*
** Public member functions
*/

void				Peon::getPolymorphed() const
{
	std::cout << this->_Name << " has been turned into a pink pony !" << std::endl;
}
