/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:57:24 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/09 16:06:15 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		static const int	MaxFixed;

		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& src);
		~Fixed(void);

		Fixed&	operator=(const Fixed& rhs);

		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					_Value;
		static const int	_FractionalBits;
};

std::ostream&	operator<<(std::ostream& o, const Fixed& i);

#endif