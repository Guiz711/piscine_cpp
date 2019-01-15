/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:48:25 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 19:28:28 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	b1("Norminet", 42);
	Form		f1("GET_CATFOOD", 50, 30);
	Form		*b18 = NULL;
	Form		f2("GET_STEAK", 20, 1);

	std::cout << f1 << std::endl;
	b1.signForm(b18);
	std::cout << f1 << std::endl;

	std::cout << f2 << std::endl;
	b1.signForm(f2);
	std::cout << f2 << std::endl;
}