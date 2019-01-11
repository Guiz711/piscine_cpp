/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:41:07 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 17:47:40 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <string>
#include <iostream>

class Victim
{
	public:
		Victim(const std::string& name);
		Victim(const Victim& src);
		virtual ~Victim(void);

		Victim&	operator=(const Victim& rhs);

		virtual void		getPolymorphed() const;

		const std::string&	getName(void) const;

	protected:
		std::string	_Name;

		Victim(void);
};

std::ostream&	operator<<(std::ostream& lfs, const Victim& rhs);

#endif