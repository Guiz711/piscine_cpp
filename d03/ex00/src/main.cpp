/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:32:05 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/10 12:59:39 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main(void)
{
	FragTrap test("Clappy");

	test.takeDamage(40);
	test.rangedAttack("badass");
	test.takeDamage(25);
	test.meleeAttack("badass");
	test.beRepaired(200);
	test.takeDamage(5000);
	test.vaulthunter_dot_exe("badass");
	test.vaulthunter_dot_exe("badass");
	test.vaulthunter_dot_exe("badass");
	test.vaulthunter_dot_exe("badass");
	test.vaulthunter_dot_exe("badass");
	test.vaulthunter_dot_exe("badass");
	test.vaulthunter_dot_exe("badass");
	test.vaulthunter_dot_exe("badass");
	test.takeDamage(200);
	return 0;
}