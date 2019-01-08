/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:05:11 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 12:11:23 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include <string>
#include "Zombie.hpp"

class ZombieEvent
{
	public:
		ZombieEvent(void);
		~ZombieEvent(void);

		void	setZombieType(std::string type);
		Zombie	*newZombie(std::string name) const;
		Zombie	*randomChump(void) const;
	
	private:
		std::string	_Type;
		static const std::string	_RandomNames[];
};

#endif
