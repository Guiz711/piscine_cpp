/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:12:48 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 17:34:06 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):
	_Name(name),
	_EquippedWeapon(NULL)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::attack(void)
{
	std::cout << this->_Name
		<< " attacks with "
		<< this->_EquippedWeapon->getType()
		<< std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_EquippedWeapon = &weapon;
}
