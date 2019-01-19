/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:38:42 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/18 15:21:06 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span {

	public:
		class NoSpaceLeftException: public std::exception
		{
			public:
				NoSpaceLeftException(void);
				NoSpaceLeftException(const NoSpaceLeftException& src);
				~NoSpaceLeftException(void) throw();

				NoSpaceLeftException&	operator=(const NoSpaceLeftException& src);

				virtual const char* 	what(void) const throw();
		};

		class NotEnoughValuesException: public std::exception
		{
			public:
				NotEnoughValuesException(void);
				NotEnoughValuesException(const NotEnoughValuesException& src);
				~NotEnoughValuesException(void) throw();

				NotEnoughValuesException&	operator=(const NotEnoughValuesException& src);

				virtual const char* 	what(void) const throw();
		};

		Span(unsigned int maxSize);
		Span(const Span &src);
		~Span(void);

		Span	&operator=(const Span &rhs);

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	private:
		unsigned int		_maxSize;
		std::vector<int>	_content;
		
		Span(void); 

};

#endif
