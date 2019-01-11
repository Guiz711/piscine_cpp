/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:40:07 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 16:17:10 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(const std::string& name, const std::string& title);
		Sorcerer(const Sorcerer& src);
		~Sorcerer(void);

		Sorcerer&	operator=(const Sorcerer& rhs);

		void				polymorph(const Victim& victim) const;

		const std::string&	getName(void) const;
		const std::string&	getTitle(void) const;

	private:
		std::string	_Name;
		std::string _Title;

		Sorcerer(void);
};

std::ostream&	operator<<(std::ostream& lfs, const Sorcerer& rhs);

#endif