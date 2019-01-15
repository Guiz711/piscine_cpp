/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:05:00 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/14 16:59:26 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	public:
		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(const GradeTooHighException& src);
				~GradeTooHighException(void) throw();

				GradeTooHighException&	operator=(const GradeTooHighException& src);

				virtual const char* 	what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(const GradeTooLowException& src);
				~GradeTooLowException(void) throw();

				GradeTooLowException&	operator=(const GradeTooLowException& src);

				virtual const char* 	what(void) const throw();
		};

		Form(const std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& src);
		~Form(void);

		void				beSigned(const Bureaucrat& signer);

		const std::string&	getName(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExecute(void) const;
		const bool&			getSignedState(void) const;

	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_isSigned;

		Form(void);

		Form&			operator=(const Form& src);
};

std::ostream&	operator<<(std::ostream& o, const Form& i);

#endif