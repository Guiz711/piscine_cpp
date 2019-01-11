/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:24:58 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 20:05:19 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

/*
** Constructors and destructor
*/

AWeapon::AWeapon(void) {}

AWeapon::AWeapon(const std::string& name, int apcost, int damage):
	_Name(name),
	_ApCost(apcost),
	_Damage(damage)
{}

AWeapon::AWeapon(const AWeapon& src):
	_Name(src.getName()),
	_ApCost(src.getApCost()),
	_Damage(src.getDamage())
{}

AWeapon::~AWeapon(void) {}

AWeapon&		AWeapon::operator=(const AWeapon& rhs)
{
	if (this == &rhs)
		return *this;

	_Name = rhs.getName();
	_ApCost = rhs.getApCost();
	_Damage = rhs.getDamage();

	return *this;
}

/*
** Public member functions
*/

std::string		AWeapon::getName() const { return _Name; }
int				AWeapon::getApCost() const { return _ApCost; }
int				AWeapon::getDamage() const { return _Damage; }