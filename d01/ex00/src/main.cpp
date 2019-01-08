/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:29:13 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 10:40:44 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	Pony	*myPony;

	myPony = new Pony();
	myPony->Eat();
	myPony->Run();
	delete myPony;
}

void	ponyOnThStack(void)
{
	Pony	myPony;

	myPony.Eat();
	myPony.Run();
}

int		main(void)
{
	ponyOnThStack();
	ponyOnTheHeap();
	return 0;
}