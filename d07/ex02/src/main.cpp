/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:02:44 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/17 18:48:37 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int		main(void)
{
	Array<int>	test(10);
	Array<std::string>	test2(3);

	test[0] = 1;
	test[1] = 2;
	for (unsigned int i = 2; i < test.size(); ++i)
	{
		test[i] = i + 1;
	}

	Array<int>	test3 = test;
	test3[8] = 42;

	Array<int>	test4(test);
	test4[1] = 42;

	for (unsigned int i = 0; i < test.size(); ++i)
	{
		std::cout << test[i] << std::endl;
	}
	std::cout << std ::endl;

	for (unsigned int i = 0; i < test3.size(); ++i)
	{
		std::cout << test3[i] << std::endl;
	}
	std::cout << std ::endl;

	for (unsigned int i = 0; i < test4.size(); ++i)
	{
		std::cout << test4[i] << std::endl;
	}
	std::cout << std ::endl;

	test2[0] = "Hi";
	test2[1] = "How are you?";

	for (unsigned int i = 0; i < test2.size(); ++i)
	{
		std::cout << test2[i] << std::endl;
	}
	std::cout << std ::endl;

	std::cout << test[8] << std::endl;
	return 0;
}
