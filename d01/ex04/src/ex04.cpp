/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:32:06 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 14:35:12 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int		main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*ptr = &str;
	std::string&	ref = str;

	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
}