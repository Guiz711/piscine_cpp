/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:11:36 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 16:17:20 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
	return;
}

Human::~Human(void)
{
	return;
}

std::string	Human::identify(void) const
{
	return this->_MyBrain.identify();
}

const Brain&	Human::getBrain(void) const
{
	return this->_MyBrain;
}
