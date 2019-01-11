/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:33:59 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 12:53:25 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(void);
		NinjaTrap(std::string name);
		NinjaTrap(const NinjaTrap& src);
		~NinjaTrap(void);

		NinjaTrap&	operator=(const NinjaTrap& rhs);

		void	ninjaShoebox(ClapTrap& puppet);
		void	ninjaShoebox(FragTrap& puppet);
		void	ninjaShoebox(ScavTrap& puppet);
		void	ninjaShoebox(NinjaTrap& puppet);

	protected:
		virtual void	introductionDialog(void) const;
		virtual void	destructionDialog(void) const;
};

#endif