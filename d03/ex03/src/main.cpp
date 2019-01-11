/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:32:05 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 13:00:46 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int		main(void)
{
	ClapTrap *clap = new ClapTrap();
	std::cout << std::endl;
	FragTrap *frag = new FragTrap("Fraggator");
	std::cout << std::endl;
	ScavTrap *scav = new ScavTrap("ScavJunk");
	std::cout << std::endl;
	NinjaTrap *ninja1 = new NinjaTrap("Shaddy");
	std::cout << std::endl;
	NinjaTrap *ninja2 = new NinjaTrap("Puppy");
	std::cout << std::endl;

	ninja1->ninjaShoebox(*clap);
	ninja1->ninjaShoebox(*frag);
	ninja1->ninjaShoebox(*scav);
	ninja1->ninjaShoebox(*ninja2);
	delete ninja1;
	delete ninja2;
	std::cout << std::endl;

	clap->takeDamage(40);
	clap->rangedAttack("badass");
	clap->takeDamage(25);
	clap->meleeAttack("badass");
	clap->beRepaired(200);
	clap->takeDamage(5000);
	clap->takeDamage(200);
	delete clap;
	std::cout << std::endl;
	frag->takeDamage(40);
	frag->rangedAttack("Handsome Jack");
	frag->takeDamage(25);
	frag->meleeAttack("Handsome Jack");
	frag->beRepaired(200);
	frag->vaulthunter_dot_exe("Handsome Jack");
	frag->vaulthunter_dot_exe("Handsome Jack");
	frag->vaulthunter_dot_exe("Handsome Jack");
	frag->vaulthunter_dot_exe("Handsome Jack");
	frag->vaulthunter_dot_exe("Handsome Jack");
	frag->takeDamage(200);
	delete frag;
	std::cout << std::endl;
	scav->rangedAttack("ZeR0");
	scav->takeDamage(25);
	scav->meleeAttack("ZeR0");
	scav->beRepaired(200);
	scav->challengeNewcomer("ZeR0");
	scav->challengeNewcomer("ZeR0");
	scav->challengeNewcomer("ZeR0");
	scav->takeDamage(200);
	delete scav;
	return 0;
}
