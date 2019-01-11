/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:32:05 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/10 16:59:34 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap frag("Clappy");
	ScavTrap scav("Scay");

	frag.takeDamage(40);
	frag.rangedAttack("badass");
	frag.takeDamage(25);
	frag.meleeAttack("badass");
	frag.beRepaired(200);
	frag.takeDamage(5000);
	frag.vaulthunter_dot_exe("badass");
	frag.vaulthunter_dot_exe("badass");
	frag.vaulthunter_dot_exe("badass");
	frag.vaulthunter_dot_exe("badass");
	frag.vaulthunter_dot_exe("badass");
	frag.vaulthunter_dot_exe("badass");
	frag.vaulthunter_dot_exe("badass");
	frag.vaulthunter_dot_exe("badass");
	frag.takeDamage(200);
	std::cout << std::endl;
	scav.rangedAttack("badass");
	scav.takeDamage(25);
	scav.meleeAttack("badass");
	scav.beRepaired(200);
	scav.takeDamage(5000);
	scav.challengeNewcomer("badass");
	scav.challengeNewcomer("badass");
	scav.challengeNewcomer("badass");
	scav.challengeNewcomer("badass");
	scav.challengeNewcomer("badass");
	scav.challengeNewcomer("badass");
	scav.challengeNewcomer("badass");
	scav.challengeNewcomer("badass");
	scav.takeDamage(200);
	return 0;
}
