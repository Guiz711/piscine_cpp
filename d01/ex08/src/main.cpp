/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:12:18 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/09 09:20:13 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main(void)
{
	Human	human;

	human.action("meleeAttack", "goblin");
	human.action("rangedAttack", "witch");
	human.action("intimidatingShout", "bandit");
	human.action("intimidatingShout", "goblin");
	human.action("Flee", "goblin");
}