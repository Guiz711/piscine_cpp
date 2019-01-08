/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:07:35 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 12:11:14 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type):
	Name(name),
	Type(type)
{
	std::cout << '<' << this->Name << " (" << this->Type << ")> Was summoned" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << '<' << this->Name << " (" << this->Type << ")> Was killed" << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << '<' << this->Name << " (" << this->Type << ")> Burp..." << std::endl;
}
