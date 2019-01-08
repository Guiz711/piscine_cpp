/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:28:20 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 12:13:42 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <iostream>

const std::string ZombieEvent::_RandomNames[] = {
	"Bob",
	"Jack",
	"Mary",
	"Lisa",
	"Jenny",
	"Stan",
	"James"
};

ZombieEvent::ZombieEvent(void)
{
	return;
}

ZombieEvent::~ZombieEvent(void)
{
	return;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->_Type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name) const
{
	return new Zombie(name, this->_Type);
}

Zombie	*ZombieEvent::randomChump(void) const
{
	int index;
	
	index = rand() % (sizeof(ZombieEvent::_RandomNames) / sizeof(std::string));
	return new Zombie(ZombieEvent::_RandomNames[index], this->_Type);
}
