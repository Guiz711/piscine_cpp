/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:34:38 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 13:02:06 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

/*
** Static parameters
*/

/*
** Constructors and destructor
*/

NinjaTrap::NinjaTrap(void):
	ClapTrap("DEFAULT-N1NJA-TP", 60, 120, 60, 5, 0)
{
	this->introductionDialog();
}

NinjaTrap::NinjaTrap(std::string name):
	ClapTrap(name, 60, 120, 60, 5, 0)
{
	this->introductionDialog();
}

NinjaTrap::NinjaTrap(const NinjaTrap& src):
	ClapTrap(src)
{
	*this = src;

	this->introductionDialog();
}

NinjaTrap&	NinjaTrap::operator=(const NinjaTrap& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

NinjaTrap::~NinjaTrap(void)
{
	this->destructionDialog();
}

/*
** Public member functions
*/

void	NinjaTrap::ninjaShoebox(ClapTrap& puppet)
{
	if (this->_EP >= 25)
	{
		this->_EP -= 25;
		std::cout << "<" << this->_Name << "> "
		<< "Hey! this piece of junk doesn't have any special skills, useless! I'll kick your butt!" << std::endl;
		puppet.takeDamage(this->_MeleeDmg);
	}
	else
	{
		std::cout << "<N1NJA-TP " << this->_Name
			<< " doesn't have enough energy points left...>" << std::endl;
	}
}

void	NinjaTrap::ninjaShoebox(FragTrap& puppet)
{
	if (this->_EP >= 25)
	{
		this->_EP -= 25;
		std::cout << "<" << this->_Name << "> "
		<< "HAHA! A FR4G-TP, excellent!" << std::endl;
		puppet.vaulthunter_dot_exe("NULL");
	}
	else
	{
		std::cout << "<SC4V-TP " << this->_Name
			<< " doesn't have enough energy points left...>" << std::endl;
	}
}

void	NinjaTrap::ninjaShoebox(ScavTrap& puppet)
{
	if (this->_EP >= 25)
	{
		this->_EP -= 25;
		std::cout << "<" << this->_Name << "> "
		<< "OW, a SC4V-TP, give me some challenge!" << std::endl;
		puppet.challengeNewcomer(this->_Name);
	}
	else
	{
		std::cout << "<SC4V-TP " << this->_Name
			<< " doesn't have enough energy points left...>" << std::endl;
	}
}

void	NinjaTrap::ninjaShoebox(NinjaTrap& puppet)
{
	if (this->_EP >= 25)
	{
		this->_EP -= 25;
		std::cout << "<" << this->_Name << "> "
		<< "Hmm...Ninjaception. "
		<< "I could give myself for your special skill but the result would bring the end of time and space. "
		<< "So instead let me heal you bro." << std::endl;
		puppet.beRepaired(this->_MeleeDmg);
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

void	NinjaTrap::introductionDialog(void) const
{
	std::cout << "<" << this->_Name << "> "
		<< "Murder, murder, murder..."
		<< std::endl;
}

void	NinjaTrap::destructionDialog(void) const
{
	std::cout << "<" << this->_Name << "> "
		<< "My work is done..."
		<< std::endl;
}
