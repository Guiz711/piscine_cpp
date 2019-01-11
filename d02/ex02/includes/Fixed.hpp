/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:57:24 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/09 18:23:13 by gmichaud         ###   ########.fr       */
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

		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);

		Fixed&	operator=(const Fixed& rhs);
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

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