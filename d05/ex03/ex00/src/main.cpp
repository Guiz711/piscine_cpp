/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:48:25 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 19:27:07 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("John", 42);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}

	try
	{
		Bureaucrat b4("Kamila", -42);
	}
	catch (std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}

	Bureaucrat b2("Kelly", 1);
	Bureaucrat b3("Jack", 150);
	Bureaucrat b5(b2);

	try
	{
		b5.incrementGrade();
	}
	catch (std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}
	try
	{
		b3.decrementGrade();
	}
	catch (std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}
}