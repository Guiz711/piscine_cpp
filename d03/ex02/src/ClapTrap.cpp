/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:20:38 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 13:05:33 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

bool		ClapTrap::_RandomInitialized = false;

/*
** Constructors and destructor
*/

ClapTrap::ClapTrap(void):
	_Name("FACTORY-NAME"),
	_Lvl(1),
	_HP(0),
	_MaxHP(0),
	_EP(0),
	_MaxEP(0),
	_MeleeDmg(0),
	_RangedDmg(0),
	_Armor(0)
{
	if (!ClapTrap::_RandomInitialized)
	{
		srand(std::time(nullptr));
		ClapTrap::_RandomInitialized = true;
	}

	std::cout << "<A lvl " << this->_Lvl << " CL4P-TP named " << this->_Name << " was created.>" << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_Name(name),
	_Lvl(1),
	_HP(0),
	_MaxHP(0),
	_EP(0),
	_MaxEP(0),
	_MeleeDmg(0),
	_RangedDmg(0),
	_Armor(0)
{
	if (!ClapTrap::_RandomInitialized)
	{
		srand(std::time(nullptr));
		ClapTrap::_RandomInitialized = true;
	}

	std::cout << "<A lvl " << this->_Lvl << " CL4P-TP named " << this->_Name << " was created.>" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int maxHP, int maxEp, int meleeDmg, int rangedDmg, int armor):
	_Name(name),
	_Lvl(1),
	_HP(maxHP),
	_MaxHP(maxHP),
	_EP(maxEp),
	_MaxEP(maxEp),
	_MeleeDmg(meleeDmg),
	_RangedDmg(rangedDmg),
	_Armor(armor)
{
	if (!ClapTrap::_RandomInitialized)
	{
		srand(std::time(nullptr));
		ClapTrap::_RandomInitialized = true;
	}

	std::cout << "<A lvl " << this->_Lvl << " CL4P-TP named " << this->_Name << " was created.>" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;

	std::cout << "<A lvl " << this->_Lvl << " CL4P-TP named " << this->_Name << " was created.>" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "<A lvl " << this->_Lvl << " CL4P-TP was destroyed.>" << std::endl;
}

/*
** Public member functions
*/

void	ClapTrap::rangedAttack(const std::string& target) const
{
	std::cout << "<CL4P-TP " << this->_Name
		<< " shoots at " << target
		<< ", causing " << this->_RangedDmg
		<< " points of damage!>" << std::endl;
}

void	ClapTrap::meleeAttack(const std::string& target) const
{
	std::cout << "<CL4P-TP " << this->_Name
		<< " stabs " << target
		<< ", causing " << this->_MeleeDmg
		<< " points of damage!>" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_HP -= amount - this->_Armor;
	if (this->_HP < 0)
		this->_HP = 0;

	std::cout << "<CL4P-TP " << this->_Name
		<< " took " << amount << " points of damage"
		<< ", his armor absorbed " << this->_Armor
		<< " points, he has now " << this->_HP
		<< " HP>" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_HP += amount;
	if (this->_HP > this->_MaxHP)
		this->_HP = this->_MaxHP;

	std::cout << "<CL4P-TP " << this->_Name
		<< " was healed of " << amount
		<< " health points, he has now " << this->_HP
		<< " HP>" << std::endl;
}
