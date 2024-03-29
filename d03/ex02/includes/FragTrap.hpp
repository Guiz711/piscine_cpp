/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:02:38 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 11:43:10 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define START_DIALOG_LEN sizeof(FragTrap::_StartDialog) / sizeof(char*)
# define END_DIALOG_LEN sizeof(FragTrap::_EndDialog) / sizeof(char*)
# define SPECIALS_LEN sizeof(FragTrap::_SpecialsList) / sizeof(SpecialAttacks)

struct SpecialAttacks
{
	std::string	Name;
	std::string Dialog;
	int			Damages;
};

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap& rhs);

		void	vaulthunter_dot_exe(std::string const & target);

	protected:
		static const char			*_StartDialog[];
		static const char			*_EndDialog[];
		static const SpecialAttacks	_SpecialsList[];
		// static bool					_RandomInitialized;

		// std::string	_Name;
		// int			_Lvl;
		// int			_HP;
		// int			_MaxHP;
		// int			_EP;
		// int			_MaxEP;
		// int			_MeleeDmg;
		// int			_RangedDmg;
		// int			_Armor;

		virtual void	introductionDialog(void) const;
		virtual void	destructionDialog(void) const;
};

#endif