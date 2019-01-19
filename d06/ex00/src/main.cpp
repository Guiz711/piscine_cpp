/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:23:18 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/16 19:25:04 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Converter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;

	try
	{
		Converter conv(argv[1]);

		std::cout << "char: ";
		try
		{
			conv.displayAsChar();
		}
		catch (std::exception& err)
		{
			std::cout << err.what();
		}
		std::cout << std::endl;
		std::cout << "int: ";
		try
		{
			conv.displayAsInt();
		}
		catch (std::exception& err)
		{
			std::cout << err.what();
		}
		std::cout << std::endl;
		std::cout << "float: ";
		try
		{
			conv.displayAsFloat();
		}
		catch (std::exception& err)
		{
			std::cout << err.what();
		}
		std::cout << std::endl;
		std::cout << "double: ";
		try
		{
			conv.displayAsDouble();
		}
		catch (std::exception& err)
		{
			std::cout << err.what();
		}
		std::cout << std::endl;
		return 0;
	}
	catch (std::exception& err)
	{
		std::cout << err.what() << std::endl;
		return 0;
	}
}