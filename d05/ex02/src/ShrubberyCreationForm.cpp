/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:33:45 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 14:20:35 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void):
	Form("Shrubbery Creation Form", 145, 137),
	_target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	Form("Shrubbery Creation Form", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
	Form("Shrubbery Creation Form", 145, 137),
	_target(src._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	(void)src;
	return *this;
}

void		ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	ofs((_target + "_shrubbery").c_str(), std::ios::out);

	if (ofs.is_open())
	{
		ofs << "        # #### ####" << std::endl
			<< "      ### \\/#|### |/####" << std::endl
			<< "     ##\\/#/ \\||/##/_/##/_#" << std::endl
			<< "   ###  \\/###|/ \\/ # ###" << std::endl
			<< " ##_\\_#\\_\\## | #/###_/_####" << std::endl
			<< "## #### # \\ #| /  #### ##/##" << std::endl
			<< " __#_--###`  |{,###---###-~" << std::endl
			<< "           \\ }{" << std::endl
			<< "            }}{" << std::endl
			<< "            }}{" << std::endl
			<< "            {{}" << std::endl
			<< "      , -=-~{ .-^- _" << std::endl
			<< "            `}" << std::endl
			<< "             {" << std::endl;

		ofs.close();
	}
	else
		std::cout << "open file error" << std::endl;

}
