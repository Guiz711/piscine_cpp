/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:42:34 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 11:51:20 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
#include "ClapTrap.hpp"

# define CHALLENGES_LEN sizeof(ScavTrap::_SpecialsList) / sizeof(Challenges)

struct Challenges
{
	std::string	Name;
	std::string Dialog;
};

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap& rhs);

		void	challengeNewcomer(std::string const & target);

	protected:
		static const Challenges		_SpecialsList[];

		virtual void	introductionDialog(void) const;
		virtual void	destructionDialog(void) const;
};

#endif