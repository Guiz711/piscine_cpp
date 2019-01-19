/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:02:44 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/18 15:33:04 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include <vector>
#include "span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span test(20000);
	std::vector<int> fill;

	srand(time(NULL));
	for(int i = 0; i < 20000; ++i)
		fill.push_back(rand());
	test.addNumber(fill.begin(), fill.end());
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	try
	{
		test.addNumber(42);
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}

	Span test1(10);

	test1.addNumber(1);
	try
	{
		std::cout << test1.longestSpan() << std::endl;
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
	return 0;
}
