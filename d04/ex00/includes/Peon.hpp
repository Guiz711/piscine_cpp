/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:18:54 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 17:47:58 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Peon: public Victim
{
	public:
		Peon(const std::string& name);
		Peon(const Peon& src);
		virtual ~Peon(void);

		Peon&	operator=(const Peon& rhs);

		virtual void	getPolymorphed() const;

	private:
		Peon(void);
};

#endif