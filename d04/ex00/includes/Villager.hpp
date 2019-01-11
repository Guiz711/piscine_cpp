/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Villager.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:52:45 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 17:53:09 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VILLAGER_HPP
# define VILLAGER_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Villager: public Victim
{
	public:
		Villager(const std::string& name);
		Villager(const Villager& src);
		virtual ~Villager(void);

		Villager&	operator=(const Villager& rhs);

		virtual void	getPolymorphed() const;

	private:
		Villager(void);
};

#endif