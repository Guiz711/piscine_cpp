/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:23:52 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/16 19:12:47 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <limits>

class Converter {

	public:
		class NonDisplayable: public std::exception
		{
			public:
				NonDisplayable(void);
				NonDisplayable(const NonDisplayable& src);
				~NonDisplayable(void) throw();

				NonDisplayable&	operator=(const NonDisplayable& src);

				virtual const char* 	what(void) const throw();
		};

		class InputNotValid: public std::exception
		{
			public:
				InputNotValid(void);
				InputNotValid(const InputNotValid& src);
				~InputNotValid(void) throw();

				InputNotValid&	operator=(const InputNotValid& src);

				virtual const char* 	what(void) const throw();
		};

		class ImpossibleConversion: public std::exception
		{
			public:
				ImpossibleConversion(void);
				ImpossibleConversion(const ImpossibleConversion& src);
				~ImpossibleConversion(void) throw();

				ImpossibleConversion&	operator=(const ImpossibleConversion& src);

				virtual const char* 	what(void) const throw();
		};

		Converter(const char	*src);
		Converter(const Converter &src);
		~Converter(void);

		Converter 			&operator=(const Converter &rhs);

		void	displayAsChar(void);
		void	displayAsInt(void);
		void	displayAsFloat(void);
		void	displayAsDouble(void);

	private:
		double	_value;

		Converter(void);
};

#endif
