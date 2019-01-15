/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:22:15 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 14:16:28 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	Form("Robotomy Request Form", 72, 45),
	_target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	Form("Robotomy Request Form", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
	Form("Robotomy Request Form", 72, 45),
	_target(src._target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	(void)src;
	return *this;
}

void		RobotomyRequestForm::executeAction(void) const
{
	std::cout << "Bzzzzzzzzz...Drzzzzzzzz..." << std::endl;
	
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}