/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:48:25 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 14:49:53 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat				b1("Norminet", 42);
	Bureaucrat				b2("Gargamel", 150);
	Bureaucrat				b3("Charly", 1);
	ShrubberyCreationForm	f1("Bocal");
	RobotomyRequestForm		f2("Marvin");
	PresidentialPardonForm	f3("Arthur Dent");

	std::cout << f1 << std::endl;
	b1.signForm(f1);
	b2.executeForm(f1);
	b1.executeForm(f1);
	b1.signForm(f2);
	b3.executeForm(f2);
	b1.signForm(f3);
	b3.executeForm(f3);
}