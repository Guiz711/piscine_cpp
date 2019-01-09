/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:56:02 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/09 09:19:59 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>

void Human::meleeAttack(std::string const & target)
{
	std::cout << "--> The human is doing a melee attack against " << target << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "--> The human is doing a ranged attack against " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "--> The human is shouting at " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	std::string	actions[3] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};

	void (Human::*actions_ptr[3])(std::string const & target) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	std::cout << "Try to " << action_name << " at " << target << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		if (action_name == actions[i])
		{
			(this->*(actions_ptr[i]))(target);
			return;
		}
	}
	std::cout << "--> A human can't do that..." << std::endl;
}
