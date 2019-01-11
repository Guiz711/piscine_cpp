/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:57:24 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/09 14:32:14 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& src);
		~Fixed(void);

		Fixed&	operator=(const Fixed& rhs);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					_Value;
		static const int	_FractionalBits;
};

#endif