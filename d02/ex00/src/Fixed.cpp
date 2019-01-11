/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:30:55 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/09 14:32:12 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** Static parameters
*/

const int	Fixed::_FractionalBits = 8;

/*
** Constructors - Destructor
*/

Fixed::Fixed(void): _Value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
** Operators overload
*/

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		this->_Value = rhs.getRawBits();	
	return *this;
}

/*
** Public member functions
*/

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->_Value;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_Value = raw;
}
