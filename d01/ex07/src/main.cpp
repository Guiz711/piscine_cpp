/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:45:35 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 19:16:14 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int	main(int argc, char **argv)
{
	if(argc != 4)
		return 0;
	if (!argv[1][0] || !argv[2][0] || !argv[3][0])
		return 0;
	Replacer test(argv[1], argv[2], argv[3]);
	test.ReplaceStringToFile();
}