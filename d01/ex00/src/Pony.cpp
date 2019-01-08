/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:36:47 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 10:52:20 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(void)
{
	std::cout << "A new pony is born! How do you want to call him?" << std::endl;
	std::cin >> this->_Name;
	std::cout << "Hir name shall be " << _Name << " then." << std::endl;
	return;
}

Pony::~Pony(void)
{
	std::cout << this->_Name << " is dead. I'm sad." << std::endl;
	return;
}

void	Pony::Eat(void) const
{
	std::cout << "The grass is yummy 'round here!" << std::endl;
}

void	Pony::Run(void) const
{
	std::cout << this->_Name << " runs in the fields!" << std::endl;
}
