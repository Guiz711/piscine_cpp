/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:20:45 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 11:58:11 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, int maxHP, int maxEp, int meleeDmg, int rangedDmg, int armor);
		ClapTrap(const ClapTrap& src);
		virtual ~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap& rhs);

		void	rangedAttack(const std::string& target) const;
		void	meleeAttack(const std::string& target) const;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		static bool					_RandomInitialized;

		std::string	_Name;
		int			_Lvl;
		int			_HP;
		int			_MaxHP;
		int			_EP;
		int			_MaxEP;
		int			_MeleeDmg;
		int			_RangedDmg;
		int			_Armor;
};

#endif