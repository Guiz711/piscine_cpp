/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:05:00 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 11:19:21 by gmichaud         ###   ########.fr       */
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

		class FormNotSignedException: public std::exception
		{
			public:
				FormNotSignedException(void);
				FormNotSignedException(const FormNotSignedException& src);
				~FormNotSignedException(void) throw();

				FormNotSignedException&	operator=(const FormNotSignedException& src);

				virtual const char* 	what(void) const throw();
		};

		Form(const std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& src);
		~Form(void);

		void				beSigned(const Bureaucrat& signer);
		void				execute(const Bureaucrat& executor) const;

		const std::string&	getName(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExecute(void) const;
		const bool&			getSignedState(void) const;

	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_isSigned;

		virtual void	executeAction(void) const = 0;;

	protected:
		Form(void);
		Form&			operator=(const Form& src);
};

std::ostream&	operator<<(std::ostream& o, const Form& i);

#endif