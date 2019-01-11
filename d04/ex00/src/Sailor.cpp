/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sailor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:51:16 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 20:13:27 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sailor.hpp"

/*
** Constructors and destructor
*/

Sailor::Sailor(void) {}

Sailor::Sailor(const std::string& name):
	Victim(name)
{
	std::cout << "Ahoi!" << std::endl;
}

Sailor::Sailor(const Sailor& src):
	Victim(src)
{
	std::cout << "Ahoi!" << std::endl;
}

Sailor::~Sailor(void)
{
	std::cout << "Bloub bloub bloub..." << std::endl;
}

Sailor&	Sailor::operator=(const Sailor& rhs)
{
	if (this == &rhs)
		return *this;

	this->_Name = rhs.getName();
	
	return *this;
}

/*
** Public member functions
*/

void				Sailor::getPolymorphed() const
{
	std::cout << this->_Name << " has been turned into a yellow jellyfish !" << std::endl;
}
