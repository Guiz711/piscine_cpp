/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:51:50 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 12:15:53 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main(void)
{
	Zombie		*hord[10];
	ZombieEvent	stalkers;
	ZombieEvent	cravers;

	srand(44313548);
	stalkers.setZombieType("stalkers");
	cravers.setZombieType("cravers");

	hord[0] = stalkers.newZombie("Guizmo");
	hord[1] = cravers.newZombie("42");

	for (unsigned int i = 2; i < 10; ++i)
	{
		if (i % 2)
			hord[i] = stalkers.randomChump();
		else
			hord[i] = cravers.randomChump();
		hord[i]->announce();
	}

	for (unsigned int i = 0; i < 10; ++i)
	{
		delete hord[i];
	}
	return 0;
}
