/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:09:01 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 14:08:18 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

// public:
// 	ZombieHorde(int N);
// 	~ZombieHorde(void);

// 	void	announce(void);

// private:
// 	static ZombieEvent	_Events[];
// 	Zombie				*_Horde;

const std::string ZombieHorde::_RandomNames[] = {
	"Bob",
	"Jack",
	"Mary",
	"Lisa",
	"Jenny",
	"Stan",
	"James"
};

ZombieHorde::ZombieHorde(int N, std::string type):
	_Horde(new Zombie[N]),
	_Size(N)
{
	int index;

	for (int i = 0; i < N; ++i)
	{
		index = rand() % (sizeof(ZombieHorde::_RandomNames) / sizeof(std::string));
		this->_Horde[i].Name = ZombieHorde::_RandomNames[index];
		this->_Horde[i].Type = type;
	}
	return;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_Horde;
	return;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->_Size; ++i)
	{
		this->_Horde[i].announce();
	}
}
