/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:24:46 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/08 10:48:17 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class	Pony
{
	public:
		Pony(void);
		~Pony();

		void	Eat() const;
		void	Run() const;

	private:
		std::string	_Name;
};

#endif