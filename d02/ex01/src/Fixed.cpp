/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:30:55 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/09 16:10:07 by gmichaud         ###   ########.fr       */
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

Fixed::Fixed(const int value):
	_Value(value << _FractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value):
	_Value(std::roundf(value * (1 << _FractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
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

int		Fixed::toInt(void) const
{
	return this->_Value >> _FractionalBits;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_Value / (float)(1 << _FractionalBits);
}


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

std::ostream&	operator<<(std::ostream& o, const Fixed& i)
{
	o << i.toFloat();
	return o;
}
