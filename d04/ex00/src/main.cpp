/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:36:46 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 17:58:18 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Villager.hpp"
#include "Sailor.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Villager franck("Franck");
	Sailor jack("Jack");

	std::cout << robert << jim << joe << franck << jack;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(franck);
	robert.polymorph(jack);

	return 0;
}
