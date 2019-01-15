/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:55:24 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 19:47:48 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const char*	Intern::_formNames[3] = {
	"PresidentialPardonForm",
	"RobotomyRequestForm",
	"ShrubberyCreationForm"
};

Intern::Intern(void)
{
	_formFactory[0] = &Intern::makePresidentialPardonForm;
	_formFactory[1] = &Intern::makeRobotomyRequestForm;
	_formFactory[2] = &Intern::makeShrubberyCreationForm;
}

Intern::Intern(const Intern& src)
{
	(void)src;
	_formFactory[0] = &Intern::makePresidentialPardonForm;
	_formFactory[1] = &Intern::makeRobotomyRequestForm;
	_formFactory[2] = &Intern::makeShrubberyCreationForm;
}

Intern::~Intern(void) {}

Intern&	Intern::operator=(const Intern& src) { (void)src; return *this; }

Form	*Intern::makeForm(std::string formName, std::string target)
{
	std::cout << "Intern creates " << formName << std::endl;
	for(int i = 0; i < 3; ++i)
	{
		if (!formName.compare(_formNames[i]))
			return (this->*(_formFactory[i]))(target);
	}
	std::cout << "Form " << formName << " doesn't exist!" << std::endl;
	return NULL;	
}

Form	*Intern::makePresidentialPardonForm(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

Form	*Intern::makeRobotomyRequestForm(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

Form	*Intern::makeShrubberyCreationForm(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}
