/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:30:55 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/09 18:21:45 by gmichaud         ###   ########.fr       */
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

Fixed::Fixed(void): _Value(0) {}

Fixed::Fixed(const int value):
	_Value(value << _FractionalBits)
{
}

Fixed::Fixed(const float value):
	_Value(std::roundf(value * (1 << _FractionalBits))) {}


Fixed::Fixed(const Fixed& src)
{
	*this = src;
	return;
}

Fixed::~Fixed(void) {}

/*
** Operators overload
*/

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
		this->_Value = rhs.getRawBits();	
	return *this;
}

Fixed&	Fixed::operator++()
{
	this->_Value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	++(*this);
	return tmp;
}

Fixed&	Fixed::operator--()
{
	this->_Value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--(*this);
	return tmp;
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return this->_Value > rhs._Value;
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return this->_Value < rhs._Value;
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return this->_Value >= rhs._Value;
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return this->_Value <= rhs._Value;
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return this->_Value == rhs._Value;
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return this->_Value != rhs._Value;
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed a;
	a.setRawBits(this->_Value + rhs.getRawBits());
	return a;
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed a;
	a.setRawBits(this->_Value - rhs.getRawBits());
	return a;
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

/*
** Static member functions
*/

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (b < a)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (b < a)
		return a;
	return b;
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
	return this->_Value;
}

void	Fixed::setRawBits(const int raw)
{
	this->_Value = raw;
}

std::ostream&	operator<<(std::ostream& o, const Fixed& i)
{
	o << i.toFloat();
	return o;
}
