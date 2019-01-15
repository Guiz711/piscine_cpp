/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:42:30 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/14 15:32:17 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
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

		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);

		void				incrementGrade(void);
		void				decrementGrade(void);

		const std::string&	getName(void) const;
		const int&			getGrade(void) const;

	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat(void);

		Bureaucrat&			operator=(const Bureaucrat& src);
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& i);

#endif
