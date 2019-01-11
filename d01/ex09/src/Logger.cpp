/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:17:42 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/10 11:07:52 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(const std::string& filePath):
	_FilePath(filePath)
{

}

Logger::~Logger(void)
{
	return;
}

std::string	Logger::getTimestamp(void) const
{
	std::time_t now;
	struct tm	timestruct;
	char		buff[19];

	now = std::time(NULL);
	timestruct = *localtime(&now);
	std::strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", &timestruct);
	return std::string(buff);
}

std::string	Logger::makeLogEntry(const std::string& message) const
{
	return (this->getTimestamp() + message);
}

void		Logger::logToConsole(const std::string& message) const
{
	std::cout << makeLogEntry(message) << std::endl;
}

void		Logger::logToFile(const std::string& message) const
{
	std::ofstream	ofs(_FilePath.c_str(), std::ios::out | std::ios::app);

	if (ofs.is_open())
		ofs << makeLogEntry(message) << std::endl;
	else
		std::cout << this->_FilePath << " couldn't be open." << std::endl;
	ofs.close();
}

void		Logger::log(const std::string& dest, const std::string& message) const
{
	std::string	destArray[2] = {
		"console",
		"file"
	};

	void (Logger::*logFunctions[3])(const std::string& message) const = {
		&Logger::logToConsole,
		&Logger::logToFile
	};

	for (int i = 0; i < 2; ++i)
	{
		if (dest == destArray[i])
		{
			(this->*(logFunctions[i]))(message);
			return;
		}
	}
	std::cout << "dest parameter invalid" << std::endl;
}
