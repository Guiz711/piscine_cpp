/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Villager.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:53:20 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 20:08:37 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Villager.hpp"

/*
** Constructors and destructor
*/

Villager::Villager(void) {}

Villager::Villager(const std::string& name):
	Victim(name)
{
	std::cout << "Hmm...hi." << std::endl;
}

Villager::Villager(const Villager& src):
	Victim(src)
{
	std::cout << "Hmm...hi." << std::endl;
}

Villager::~Villager(void)
{
	std::cout << "Goodbye I guess..." << std::endl;
}

Villager&	Villager::operator=(const Villager& rhs)
{
	if (this == &rhs)
		return *this;

	this->_Name = rhs.getName();
	
	return *this;
}

/*
** Public member functions
*/

void				Villager::getPolymorphed() const
{
	std::cout << this->_Name << " has been turned into a rainbow pig !" << std::endl;
}