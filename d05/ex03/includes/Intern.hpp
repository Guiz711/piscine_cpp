/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:55:22 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 19:42:54 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>

class Form;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& src);
		~Intern(void);

		Intern&	operator=(const Intern& src);

		Form	*makeForm(std::string formName, std::string target);
	private:
		static const char*	_formNames[3];
		Form* (Intern::*_formFactory[3])(std::string const & target);

		Form	*makePresidentialPardonForm(std::string const & target);
		Form	*makeRobotomyRequestForm(std::string const & target);
		Form	*makeShrubberyCreationForm(std::string const & target);
};

#endif