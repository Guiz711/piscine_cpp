/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:01:57 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 19:13:35 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <string>
# include <iostream>
# include <fstream>

class Replacer
{
	public:
		Replacer(std::string filePath, std::string needle, std::string placeHolder);
		~Replacer(void);

		void	PrintReplaceString(void) const;
		void	ReplaceStringToFile(void) const;

	private:
		std::string	_Needle;
		std::string	_Placeholder;
		std::string	_Content;
		std::string _FilePath;

		void	ReplaceNeedle();
};

#endif