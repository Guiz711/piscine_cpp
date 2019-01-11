/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sailor.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:50:19 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 17:50:58 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAILOR_HPP
# define SAILOR_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Sailor: public Victim
{
	public:
		Sailor(const std::string& name);
		Sailor(const Sailor& src);
		virtual ~Sailor(void);

		Sailor&	operator=(const Sailor& rhs);

		virtual void	getPolymorphed() const;

	private:
		Sailor(void);
};

#endif