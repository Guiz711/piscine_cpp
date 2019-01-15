/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:48:25 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 19:42:13 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat				b1("Norminet", 1);
	Intern					i1;

	Form *test = i1.makeForm("RobotomyRequestForm", "Arthur Dent");
	if (test != NULL)
	{
		b1.signForm(*test);
		b1.executeForm(*test);
	}
	delete test;
	test = i1.makeForm("Yolo", "Arthur Dent");
	if (test != NULL)
	{
		b1.signForm(*test);
		b1.executeForm(*test);
	}
	return 0;
}