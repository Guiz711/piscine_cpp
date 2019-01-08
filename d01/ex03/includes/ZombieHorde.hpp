/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:07:45 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 14:03:23 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

#include <string>
#include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int N, std::string type);
		~ZombieHorde(void);

		void	announce(void);

	private:
		static const std::string	_RandomNames[];
		Zombie						*_Horde;
		int							_Size; 
};

# endif