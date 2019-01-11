/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:02:38 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 17:30:10 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>

# define START_DIALOG_LEN sizeof(FragTrap::_StartDialog) / sizeof(char*)
# define END_DIALOG_LEN sizeof(FragTrap::_EndDialog) / sizeof(char*)
# define SPECIALS_LEN sizeof(FragTrap::_SpecialsList) / sizeof(SpecialAttacks)

struct SpecialAttacks
{
	std::string	Name;
	std::string Dialog;
	int			Damages;
};

class FragTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap& rhs);

		void	rangedAttack(const std::string& target) const;
		void	meleeAttack(const std::string& target) const;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	vaulthunter_dot_exe(std::string const & target);

		const std::string&	getName(void) const;
		const int&			getLvl(void) const;
		const int&			getHP(void) const;
		const int&			getMaxHP(void) const;
		const int&			getEP(void) const;
		const int&			getMaxEP(void) const;
		const int&			getMeleeDmg(void) const;
		const int&			getRangedDmg(void) const;
		const int&			getArmor(void) const;

	private:
		static const char			*_StartDialog[];
		static const char			*_EndDialog[];
		static const SpecialAttacks	_SpecialsList[];
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

		virtual void	introductionDialog(void) const;
		virtual void	destructionDialog(void) const;
};

#endif