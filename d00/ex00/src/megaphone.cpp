/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:03:23 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/07 13:19:37 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(int argc, char **argv)
{
	std::string	s;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; ++i)
	{
		s = argv[i];
		for (size_t j = 0; j < s.length(); ++j)
			s[j] = std::toupper(s[j]);
		std::cout << s;
	}
	std::cout << std::endl;
	return 0;
}