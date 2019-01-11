/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:16:41 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 13:04:19 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** Static parameters
*/

const char	*FragTrap::_StartDialog[] = {
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

const char	*FragTrap::_EndDialog[] = {
	"NOOO!",
	"Poop.",
	"I'll get you next time!",
	"No fair! I wasn't ready.",
	"You got me!",
	"Argh arghargh death gurgle gurglegurgle urgh... death.",
	"Oh well.",
	"Crap happens."
};

const SpecialAttacks	FragTrap::_SpecialsList[] = {
	{"Pirate Ship Mode", "Avast ye scurvy dogs!", 75},
	{"Meat Unicycle", "(unintelligible snarling)", 45},
	{"Mechromagician", "Anarchy and mini-trap and awesomeness, oh my!", 60},
	{"Rubber Ducky", "Trouncy, flouncy... founcy... those aren't words.", 2},
	{"Useless Bip", "Bip boop boop bip...Oh shit.", 0}
};

bool		FragTrap::_RandomInitialized = false;

/*
** Constructors and destructor
*/

FragTrap::FragTrap(void):
	_Name("FACTORY_NAME"),
	_Lvl(1),
	_HP(100),
	_MaxHP(100),
	_EP(100),
	_MaxEP(100),
	_MeleeDmg(30),
	_RangedDmg(20),
	_Armor(5)
{
	if (!FragTrap::_RandomInitialized)
	{
		srand(std::time(nullptr));
		FragTrap::_RandomInitialized = true;
	}

	std::cout << "<A lvl " << this->_Lvl << " FR4G-TP was created.>" << std::endl
		<< "<" << this->_Name << "> "
		<< FragTrap::_StartDialog[rand() % START_DIALOG_LEN]
		<< std::endl;
}

FragTrap::FragTrap(std::string name):
	_Name(name),
	_Lvl(1),
	_HP(100),
	_MaxHP(100),
	_EP(100),
	_MaxEP(100),
	_MeleeDmg(30),
	_RangedDmg(20),
	_Armor(5)
{
	if (!FragTrap::_RandomInitialized)
	{
		srand(std::time(nullptr));
		FragTrap::_RandomInitialized = true;
	}

	std::cout << "<A lvl " << this->_Lvl << " FR4G-TP was created.>" << std::endl
		<< "<" << this->_Name << "> "
		<< FragTrap::_StartDialog[rand() % START_DIALOG_LEN]
		<< std::endl;
}

FragTrap::FragTrap(const FragTrap& src)
{
	*this = src;

	std::cout << "<A lvl " << this->_Lvl << " FR4G-TP was created.>" << std::endl
		<< "<" << this->_Name << "> "
		<< FragTrap::_StartDialog[rand() % START_DIALOG_LEN]
		<< std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "<A lvl " << this->_Lvl << " FR4G-TP was destroyed.>" << std::endl
		<< "<" << this->_Name << "> "
		<< FragTrap::_EndDialog[rand() % END_DIALOG_LEN]
		<< std::endl;
}

/*
** Public member functions
*/

void	FragTrap::rangedAttack(const std::string& target) const
{
	std::cout << "<FR4G-TP " << this->_Name
		<< " shoots at " << target
		<< ", causing " << this->_RangedDmg
		<< " points of damage!>" << std::endl;
}

void	FragTrap::meleeAttack(const std::string& target) const
{
	std::cout << "<FR4G-TP " << this->_Name
		<< " stabs " << target
		<< ", causing " << this->_MeleeDmg
		<< " points of damage!>" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	this->_HP -= amount - this->_Armor;
	if (this->_HP < 0)
		this->_HP = 0;

	std::cout << "<FR4G-TP " << this->_Name
		<< " took " << amount << " points of damage"
		<< ", his armor absorbed " << this->_Armor
		<< " points, he has now " << this->_HP
		<< " HP>" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	this->_HP += amount;
	if (this->_HP > this->_MaxHP)
		this->_HP = this->_MaxHP;

	std::cout << "<FR4G-TP " << this->_Name
		<< " was healed of " << amount
		<< " health points, he has now " << this->_HP
		<< " HP>" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	SpecialAttacks attack = FragTrap::_SpecialsList[rand() % SPECIALS_LEN];

	if (this->_EP >= 25)
	{
		this->_EP -= 25;
		std::cout << "<FR4G-TP " << this->_Name
			<< " launches VaultHunter.EXE... "
			<< " random started... " << attack.Name
			<< " was chosen, causing " << attack.Damages
			<< " points of damage to " << target << "!>" << std::endl
			<< "<" << this->_Name << "> " << attack.Dialog << std::endl
			<< "<FR4G-TP " << this->_Name
			<< " now has " << this->_EP
			<< " / " << this->_MaxEP << " EP>" << std::endl;
	}
	else
	{
		std::cout << "<FR4G-TP " << this->_Name
			<< " doesn't have enough energy points left...>" << std::endl;
	}
}

/*
** Private member functions
*/
