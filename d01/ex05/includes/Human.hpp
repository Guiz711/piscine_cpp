/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:40:01 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 16:14:19 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class Human
{
	public:
		Human(void);
		~Human(void);

		std::string		identify(void) const;
		const Brain&	getBrain(void) const;

	private:
		const Brain	_MyBrain;
};

#endif