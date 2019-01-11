/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:59:55 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/11 20:15:17 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon
{
	public:
		AWeapon(const std::string& name, int apcost, int damage);
		AWeapon(const AWeapon& src);
		~AWeapon(void);

		AWeapon&		operator=(const AWeapon& rhs);

		virtual void	attack() const = 0;

		std::string		getName() const;
		int				getApCost() const;
		int				getDamage() const;

	private:
		std::string		_Name;
		int				_ApCost;
		int				_Damage;

		AWeapon(void);

};

#endif