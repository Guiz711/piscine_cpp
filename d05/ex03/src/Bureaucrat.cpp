/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:49:04 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 19:48:31 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void):
	_name("default"),
	_grade(150)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade):
	_name(name),
	_grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src):
	_name(src._name),
	_grade(src._grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src) {
	(void)src;
	return *this;
}

void		Bureaucrat::signForm(Form& formToSign) const
{
	try
	{
		formToSign.beSigned(*this);
		std::cout << _name << " signs " << formToSign.getName() << std::endl;
	}
	catch (std::exception& err)
	{
		std::cout << _name << " cannot sign " << formToSign.getName() 
			<< " because his grade is " << _grade << " and should be at least "
			<< formToSign.getGradeToSign() << std::endl;	
	}
}

void		Bureaucrat::executeForm(const Form& form) const
{
	try
	{
		std::cout << _name << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch (std::exception& err)
	{
		std::cout << _name << " cannot execute " << form.getName() 
			<< " because his grade is " << _grade << " and should be at least "
			<< form.getGradeToSign() << std::endl;	
	}
}

void		Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void		Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

const std::string&	Bureaucrat::getName(void) const { return _name; }
const int&			Bureaucrat::getGrade(void) const { return _grade; }

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException& src) { (void)src; }
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

Bureaucrat::GradeTooHighException&	Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException& src)
{
	(void)src;
	return *this;
}

const char* 	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "The grade is too high, it should be more than 1.";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException& src) { (void)src; }
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

Bureaucrat::GradeTooLowException&	Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException& src)
{
	(void)src;
	return *this;
}

const char* 	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "The grade is too low, it should be less than 150.";
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}
