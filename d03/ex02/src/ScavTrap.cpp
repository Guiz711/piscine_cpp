/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:16:41 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 20:10:42 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** Static parameters
*/

const Challenges	ScavTrap::_SpecialsList[] = {
	{"Ice Bucket", "Go get some ice and chew it!"},
	{"Tiny Tina", "Go have a role playing session with Tiny Tina!"},
	{"Butt Stallion", "Find Handsome Jack's Butt Stallion and bring me it's tail"},
	{"CL4P-TP", "Hack a CL4P-TP and make him dance (actually, they can do that by default...)"}
};

/*
** Constructors and destructor
*/

ScavTrap::ScavTrap(void):
	ClapTrap("DEFAULT-SC4V-TP", 100, 50, 20, 15, 3)
{
	this->introductionDialog();
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name, 100, 50, 20, 15, 3)
{
	this->introductionDialog();
}

ScavTrap::ScavTrap(const ScavTrap& src):
	ClapTrap(src)
{
	*this = src;

	this->introductionDialog();
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	if (this == &src)
		return *this;

	_Name = src.getName();
	_Lvl = src.getLvl();
	_HP = src.getHP();
	_MaxHP = src.getMaxHP();
	_EP = src.getEP();
	_MaxEP = src.getMaxEP();
	_MeleeDmg = src.getMeleeDmg();
	_RangedDmg = src.getRangedDmg();
	_Armor = src.getArmor();

	return *this;
}

ScavTrap::~ScavTrap(void)
{
	this->destructionDialog();
}

/*
** Public member functions
*/

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	Challenges attack = ScavTrap::_SpecialsList[rand() % CHALLENGES_LEN];

	if (this->_EP >= 25)
	{
		this->_EP -= 25;
		std::cout << "<SC4V-TP " << this->_Name
			<< " chooses a random challenge for " << target << "... "
			<< attack.Name << " challenge was chosen!>" << std::endl
			<< "<" << this->_Name << "> " << attack.Dialog << std::endl
			<< "<SC4V-TP " << this->_Name
			<< " now has " << this->_EP
			<< " / " << this->_MaxEP << " EP>" << std::endl;
	}
	else
	{
		std::cout << "<SC4V-TP " << this->_Name
			<< " doesn't have enough energy points left...>" << std::endl;
	}
}

/*
** Protected member functions
*/

void	ScavTrap::introductionDialog(void) const
{
	std::cout << "<" << this->_Name << "> "
		<< "Hello my lord."
		<< std::endl;
}

void	ScavTrap::destructionDialog(void) const
{
	std::cout << "<" << this->_Name << "> "
		<< "Go f*** yoursel my lord."
		<< std::endl;
}
