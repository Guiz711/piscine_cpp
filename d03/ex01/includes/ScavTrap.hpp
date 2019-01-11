/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:42:34 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/10 16:57:27 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

# define START_SC4V_LEN sizeof(ScavTrap::_StartDialog) / sizeof(char*)
# define END_SC4V_LEN sizeof(ScavTrap::_EndDialog) / sizeof(char*)
# define CHALLENGES_LEN sizeof(ScavTrap::_SpecialsList) / sizeof(Challenges)

struct Challenges
{
	std::string	Name;
	std::string Dialog;
};

class ScavTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap& rhs);

		void	rangedAttack(const std::string& target) const;
		void	meleeAttack(const std::string& target) const;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer(std::string const & target);

	protected:
		static const char			*_StartDialog[];
		static const char			*_EndDialog[];
		static const Challenges		_SpecialsList[];
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