/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:02:44 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/18 11:07:20 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include <vector>
#include "easyfind.hpp"

int		main(void)
{
	std::array<int, 5>		test = {{ 0, 1, 2, 3, 4 }};
	std::vector<int>	test2(200, 10);
	int n;

	n = easyfind(test, 2);
	std::cout << n << std::endl;

	n = easyfind(test2, 42);
	std::cout << n << std::endl;
	test2[42] = 42;
	n = easyfind(test2, 42);
	std::cout << n << std::endl;
	
	return 0;
}
