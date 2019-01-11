/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:20:45 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 17:36:31 by gmichaud         ###   ########.fr       */
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

		const std::string&	getName(void) const;
		const int&			getLvl(void) const;
		const int&			getHP(void) const;
		const int&			getMaxHP(void) const;
		const int&			getEP(void) const;
		const int&			getMaxEP(void) const;
		const int&			getMeleeDmg(void) const;
		const int&			getRangedDmg(void) const;
		const int&			getArmor(void) const;

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