/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:01:57 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/10 11:04:28 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <fstream>

class Logger
{
	public:
		Logger(const std::string& filePath);
		~Logger(void);

		void	log(const std::string& dest, const std::string& message) const;

	private:
		std::string _FilePath;

		std::string	getTimestamp(void) const;
		void		logToConsole(const std::string& message) const;
		void		logToFile(const std::string& message) const;
		std::string	makeLogEntry(const std::string& message) const;
};

#endif