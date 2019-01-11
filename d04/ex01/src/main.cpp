/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:52:51 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 19:54:55 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"

int main(void)
{
	AWeapon test("blabla", 2, 5);
	AWeapon test1 = test;

	std::cout << test1.getName() << std::endl;
}