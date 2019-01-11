/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:45:35 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/10 11:17:54 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
		return 0;
	Logger test(argv[1]);
	test.log("console", "HELLO");
	test.log("file", "HELLO File");
	test.log("console", "This is a log!");
	test.log("file", "This is a log to a file!");
	test.log("file", "Bye");
}