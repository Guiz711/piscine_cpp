/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:39:19 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/18 15:23:35 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

Span::Span(unsigned int maxSize):
	_maxSize(maxSize)
{}

Span::Span(const Span &src):
	_maxSize(src._maxSize)
{
	std::copy(src._content.begin(), src._content.end(), std::back_inserter(_content));
}

Span	&Span::operator=(const Span &rhs)
{
	if (this == &rhs)
		return *this;

	_maxSize = rhs._maxSize;
	std::copy(rhs._content.begin(), rhs._content.end(), std::back_inserter(_content));
	return *this;
}


Span::~Span(void) {}

void	Span::addNumber(int n)
{
	if (_content.size() >= _maxSize)
		throw NoSpaceLeftException();
	_content.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	std::copy(start, end, std::back_inserter(_content));
}

int		Span::shortestSpan(void) const
{
	std::vector<int>			cpy;
	int							minSpan = -1;

	if (_content.size() < 2)
		throw NotEnoughValuesException();

	std::copy(_content.begin(), _content.end(), std::back_inserter(cpy));
	std::sort<int>(cpy.begin(), cpy.end());

	std::vector<int>::iterator	prev = cpy.begin();
	for (std::vector<int>::iterator curr = prev + 1; curr != cpy.end(); ++curr)
	{
		if (minSpan == -1 || std::abs(*curr - *prev) < minSpan)
			minSpan = std::abs(*curr - *prev);
		++prev;
	}
	return minSpan;
}

int		Span::longestSpan(void) const
{
	if (_content.size() < 2)
		throw NotEnoughValuesException();

	int max = *std::min_element(_content.begin(), _content.end());
	int min = *std::max_element(_content.begin(), _content.end());
	return (std::abs(max - min));
}

Span::NoSpaceLeftException::NoSpaceLeftException(void) {}
Span::NoSpaceLeftException::NoSpaceLeftException(const NoSpaceLeftException& src) { (void)src; }
Span::NoSpaceLeftException::~NoSpaceLeftException(void) throw() {}

Span::NoSpaceLeftException&	Span::NoSpaceLeftException::operator=(const NoSpaceLeftException& src)
{
	(void)src;
	return *this;
}

const char* 	Span::NoSpaceLeftException::what(void) const throw()
{
	return "There is no space left in this container.";
}

Span::NotEnoughValuesException::NotEnoughValuesException(void) {}
Span::NotEnoughValuesException::NotEnoughValuesException(const NotEnoughValuesException& src) { (void)src; }
Span::NotEnoughValuesException::~NotEnoughValuesException(void) throw() {}

Span::NotEnoughValuesException&	Span::NotEnoughValuesException::operator=(const NotEnoughValuesException& src)
{
	(void)src;
	return *this;
}

const char* 	Span::NotEnoughValuesException::what(void) const throw()
{
	return "There are not enough values to calculate span.";
}
