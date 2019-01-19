/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:44:50 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/18 09:59:50 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {

	private:
		T				*_content;
		unsigned int	_length;

	public:
		class OutOfBounds: public std::exception
		{
			public:
				OutOfBounds(void) {};
				OutOfBounds(const OutOfBounds& src) { (void)src; };
				~OutOfBounds(void) throw() {};

				OutOfBounds&	operator=(const OutOfBounds& src)
				{
					(void)src;
					return *this;
				};

				virtual const char* 	what(void) const throw()
				{
					return "Index is out of bounds";
				};
		};

		Array(void):
			_content(new T[0]),
			_length(0)
		{};

		Array(unsigned int n):
			_content(new T[n]),
			_length(n)
		{};

		Array(const Array &src):
			_content(new T[src._length]),
			_length(src._length)
		{
			for (unsigned int i = 0; i < _length; ++i)
			{
				_content[i] = src._content[i];
			}
		};

		~Array(void)
		{
			delete [] _content;
			return;
		};

		Array<T>			&operator=(const Array &rhs)
		{
			if (this == &rhs)
				return *this;

			_content = new T[rhs._length];
			_length = rhs._length;

			for (unsigned int i = 0; i < _length; ++i)
			{
				_content[i] = rhs._content[i];
			}
			return *this;
		};

		T 					&operator[](unsigned int i)
		{
			if (i < _length)
				return _content[i];
			throw OutOfBounds();
		};

		unsigned int		size(void) const
		{
			return _length;
		};
};

#endif
