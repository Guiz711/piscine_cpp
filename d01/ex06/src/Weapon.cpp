/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:37:27 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 17:14:19 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type):
	_Type(type)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

const std::string&	Weapon::getType(void) const
{
	return this->_Type;
}

void				Weapon::setType(const std::string type)
{
	this->_Type = type;
}

