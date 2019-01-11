/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:16:41 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 20:09:27 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** Static parameters
*/

const char	*ScavTrap::_StartDialog[] = {
	"Hello my lord.",
};

const char	*ScavTrap::_EndDialog[] = {
	"Go f*** yoursel my lord."
};

const Challenges	ScavTrap::_SpecialsList[] = {
	{"Ice Bucket", "Go get some ice and chew it!"},
	{"Tiny Tina", "Go have a role playing session with Tiny Tina!"},
	{"Butt Stallion", "Find Handsome Jack's Butt Stallion and bring me it's tail"},
	{"CL4P-TP", "Hack a CL4P-TP and make him dance (actually, they can do that by default...)"}
};

bool		ScavTrap::_RandomInitialized = false;

/*
** Constructors and destructor
*/

ScavTrap::ScavTrap(void):
	_Name("FACTORY_NAME"),
	_Lvl(1),
	_HP(100),
	_MaxHP(100),
	_EP(50),
	_MaxEP(50),
	_MeleeDmg(20),
	_RangedDmg(15),
	_Armor(3)
{
	if (!ScavTrap::_RandomInitialized)
	{
		srand(std::time(nullptr));
		ScavTrap::_RandomInitialized = true;
	}

	this->introductionDialog();
}

ScavTrap::ScavTrap(std::string name):
	_Name(name),
	_Lvl(1),
	_HP(100),
	_MaxHP(100),
	_EP(50),
	_MaxEP(50),
	_MeleeDmg(20),
	_RangedDmg(15),
	_Armor(3)
{
	if (!ScavTrap::_RandomInitialized)
	{
		srand(std::time(nullptr));
		ScavTrap::_RandomInitialized = true;
	}

	this->introductionDialog();
}

ScavTrap::ScavTrap(const ScavTrap& src):
	_Name(src.getName()),
	_Lvl(src.getLvl()),
	_HP(src.getHP()),
	_MaxHP(src.getMaxHP()),
	_EP(src.getEP()),
	_MaxEP(src.getMaxEP()),
	_MeleeDmg(src.getMeleeDmg()),
	_RangedDmg(src.getRangedDmg()),
	_Armor(src.getArmor())
{
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

void	ScavTrap::rangedAttack(const std::string& target) const
{
	std::cout << "<SC4V-TP " << this->_Name
		<< " shoots at " << target
		<< ", causing " << this->_RangedDmg
		<< " points of damage!>" << std::endl;
}

void	ScavTrap::meleeAttack(const std::string& target) const
{
	std::cout << "<SC4V-TP " << this->_Name
		<< " stabs " << target
		<< ", causing " << this->_MeleeDmg
		<< " points of damage!>" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	this->_HP -= amount - this->_Armor;
	if (this->_HP < 0)
		this->_HP = 0;

	std::cout << "<SC4V-TP " << this->_Name
		<< " took " << amount << " points of damage"
		<< ", his armor absorbed " << this->_Armor
		<< " points, he has now " << this->_HP
		<< " HP>" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	this->_HP += amount;
	if (this->_HP > this->_MaxHP)
		this->_HP = this->_MaxHP;

	std::cout << "<SC4V-TP " << this->_Name
		<< " was healed of " << amount
		<< " health points, he has now " << this->_HP
		<< " HP>" << std::endl;
}

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

const std::string&	ScavTrap::getName(void) const { return this->_Name; }
const int&			ScavTrap::getLvl(void) const { return this->_Lvl; };
const int&			ScavTrap::getHP(void) const { return this->_HP; };
const int&			ScavTrap::getMaxHP(void) const { return this->_MaxHP; };
const int&			ScavTrap::getEP(void) const { return this->_EP; };
const int&			ScavTrap::getMaxEP(void) const { return this->_MaxEP; };
const int&			ScavTrap::getMeleeDmg(void) const { return this->_MeleeDmg; };
const int&			ScavTrap::getRangedDmg(void) const { return this->_RangedDmg; };
const int&			ScavTrap::getArmor(void) const { return this->_Armor; };

/*
** Private member functions
*/

void	ScavTrap::introductionDialog(void) const
{
	std::cout << "<A lvl " << this->_Lvl << " SC4V-TP was created.>" << std::endl
		<< "<" << this->_Name << "> "
		<< ScavTrap::_StartDialog[rand() % START_SC4V_LEN]
		<< std::endl;
}

void	ScavTrap::destructionDialog(void) const
{
	std::cout << "<A lvl " << this->_Lvl << " SC4V-TP was destroyed.>" << std::endl
		<< "<" << this->_Name << "> "
		<< ScavTrap::_EndDialog[rand() % END_SC4V_LEN]
		<< std::endl;
}
