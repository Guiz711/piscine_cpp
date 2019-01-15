/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:27:43 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 14:30:10 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	Form("Presidential Pardon Form", 25, 5),
	_target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	Form("Robotomy Request Form", 72, 45),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src):
	Form("Robotomy Request Form", 72, 45),
	_target(src._target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	(void)src;
	return *this;
}

void		PresidentialPardonForm::executeAction(void) const
{
	std::cout << _target
		<< " has been pardonned by Zaphod Beeblebrox." << std::endl;
}