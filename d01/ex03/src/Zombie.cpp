/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:07:35 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 13:49:12 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
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
