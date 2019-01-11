/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:16:41 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 12:59:57 by gmichaud         ###   ########.fr       */
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

/*
** Constructors and destructor
*/

FragTrap::FragTrap(void):
	ClapTrap("DEFAULT-FR4G-TP", 100, 100, 30, 20, 5)
{
	this->introductionDialog();
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name, 100, 100, 30, 20, 5)
{
	this->introductionDialog();
}

FragTrap::FragTrap(const FragTrap& src):
	ClapTrap(src)
{
	*this = src;

	this->introductionDialog();
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

FragTrap::~FragTrap(void)
{
	this->destructionDialog();
}

/*
** Public member functions
*/

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
** Protected member functions
*/

void	FragTrap::introductionDialog(void) const
{
	std::cout << "<" << this->_Name << "> "
		<< FragTrap::_StartDialog[rand() % START_DIALOG_LEN]
		<< std::endl;
}

void	FragTrap::destructionDialog(void) const
{
	std::cout << "<" << this->_Name << "> "
		<< FragTrap::_EndDialog[rand() % END_DIALOG_LEN]
		<< std::endl;
}
