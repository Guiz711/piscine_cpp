/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:17:42 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 19:22:18 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string filePath, std::string needle, std::string placeHolder):
	_Needle(needle),
	_Placeholder(placeHolder),
	_FilePath(filePath)
{
	std::ifstream	ifs(filePath);
	std::string		line;

	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			this->_Content += line + "\n";
		}
	}
	ifs.close();
	this->ReplaceNeedle();
}

Replacer::~Replacer(void)
{
	return;
}

void	Replacer::PrintReplaceString(void) const
{
	std::cout << this->_Content << std::endl;
}

void	Replacer::ReplaceStringToFile(void) const
{
	if(this->_Content.empty())
		return;

	std::ofstream	ofs(_FilePath + ".replace");

	if (ofs.is_open())
	{
		ofs << this->_Content;
	}
	ofs.close();
}

void	Replacer::ReplaceNeedle()
{
	std::string	dest;
	size_t		pos;
	size_t		found;

	pos = 0;
	while (pos < this->_Content.length())
	{
		found = this->_Content.find(this->_Needle, pos);
		if (found != std::string::npos)
		{
			dest += this->_Content.substr(pos, found - pos);
			dest += this->_Placeholder;
			pos = found + this->_Needle.length();
		}
		else
		{
			dest += this->_Content.substr(pos, this->_Content.length() - pos);
			break;
		}
	}
	this->_Content = dest;
}
