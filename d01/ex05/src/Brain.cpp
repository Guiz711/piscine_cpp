/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:47:40 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 16:08:48 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	return;
}

Brain::~Brain(void)
{
	return;
}

std::string	Brain::identify(void) const
{
	std::stringstream ss;

	ss << this;
	return ss.str();
}