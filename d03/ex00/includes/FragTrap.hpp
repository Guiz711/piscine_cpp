/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 09:02:38 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/10 14:36:52 by gmichaud         ###   ########.fr       */
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
};

#endif