/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:29:13 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/09 18:34:47 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
# include <iostream>

void	ponyOnTheHeap(void)
{
	Pony	*myPony;

	std::cout << "ponyOntheHeap" << std::endl;
	myPony = new Pony();
	myPony->Eat();
	delete myPony;
	myPony = NULL;
	if(myPony != NULL)
		myPony->Run();
	else
		std::cout << "this pony can't run, he's already dead..." << std::endl;
}

void	ponyOnThStack(void)
{
	Pony	myPony;

	std::cout << "ponyOntheStack" << std::endl;
	myPony.Eat();
	myPony.Run();
}

int		main(void)
{
	ponyOnTheHeap();
	ponyOnThStack();
	return 0;
}