/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:23:30 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/16 19:23:27 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <iostream>
#include <iomanip>

Converter::Converter(void) {}

Converter::Converter(const Converter &src):
	_value(src._value)
{}

Converter::Converter(const char *src) {
	char *end;

	_value = std::strtod(src, &end);
	if (*end)
		throw InputNotValid();
}

Converter::~Converter(void) {}

Converter 	&Converter::operator=(const Converter &rhs)
{
	if (this == &rhs)
		return *this;
	
	_value = rhs._value;

	return *this;
}

void	Converter::displayAsChar(void)
{
	char c = static_cast<char>(_value);

	if (_value != _value
		|| static_cast<double>(std::numeric_limits<char>::max()) < _value
		|| static_cast<double>(std::numeric_limits<char>::min()) > _value)
		throw ImpossibleConversion();
	if (!std::isprint(c))
		throw NonDisplayable();
	std::cout << c;
}

void	Converter::displayAsInt(void)
{
	int i = static_cast<int>(_value);

	if (_value != _value
		|| static_cast<double>(std::numeric_limits<int>::max()) < _value
		|| static_cast<double>(std::numeric_limits<int>::min()) > _value)
		throw ImpossibleConversion();
	std::cout << i;
}

void	Converter::displayAsFloat(void)
{
	float f = static_cast<float>(_value);

	if (f - static_cast<float>(static_cast<int>(f)) == 0.0)
		std::cout << std::setprecision(1) << std::fixed << f;
	else
		std::cout << f;
}

void	Converter::displayAsDouble(void)
{
	if (_value - static_cast<float>(static_cast<int>(_value)) == 0.0)
		std::cout << std::setprecision(1) << std::fixed << _value;
	else
		std::cout << _value;
}

Converter::NonDisplayable::NonDisplayable(void) {}
Converter::NonDisplayable::NonDisplayable(const NonDisplayable& src) { (void)src; }
Converter::NonDisplayable::~NonDisplayable(void) throw() {}

Converter::NonDisplayable&	Converter::NonDisplayable::operator=(const NonDisplayable& src)
{
	(void)src;
	return *this;
}

const char* 	Converter::NonDisplayable::what(void) const throw()
{
	return "Non displayable";
}

Converter::InputNotValid::InputNotValid(void) {}
Converter::InputNotValid::InputNotValid(const InputNotValid& src) { (void)src; }
Converter::InputNotValid::~InputNotValid(void) throw() {}

Converter::InputNotValid&	Converter::InputNotValid::operator=(const InputNotValid& src)
{
	(void)src;
	return *this;
}

const char* 	Converter::InputNotValid::what(void) const throw()
{
	return "Input not valid";
}

Converter::ImpossibleConversion::ImpossibleConversion(void) {}
Converter::ImpossibleConversion::ImpossibleConversion(const ImpossibleConversion& src) { (void)src; }
Converter::ImpossibleConversion::~ImpossibleConversion(void) throw() {}

Converter::ImpossibleConversion&	Converter::ImpossibleConversion::operator=(const ImpossibleConversion& src)
{
	(void)src;
	return *this;
}

const char* 	Converter::ImpossibleConversion::what(void) const throw()
{
	return "impossible";
}