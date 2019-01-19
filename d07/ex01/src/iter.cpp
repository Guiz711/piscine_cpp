/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:02:44 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/17 11:33:50 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
void	iter(T *array, size_t size, void (*f)(T&))
{
	if (!array)
		return;
	
	while(size--)
	{
		f(*array++);
	}
}

void	add42(int &x)
{
	x += 42;
}

template <typename T>
void	print(T &x)
{
	std::cout << x << std::endl;
}

int		main(void)
{
	int	test[] = {0, 1, 2, 3, 4, 5, 6};
	std::string test2[] = {
		"Hi",
		"How are you?",
		"Norminet is the best"
	};

	iter<int>(test, 7, print<int>);
	iter<int>(test, 7, add42);
	iter<int>(test, 7, print<int>);
	iter<std::string>(test2, 3, print<std::string>);
	return 0;
}