/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:05:05 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/15 11:14:05 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):
	_name("default"),
	_gradeToSign(150),
	_gradeToExecute(150),
	_isSigned(false)
{}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_isSigned(false)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& src):
	_name(src._name),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute),
	_isSigned(false)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form(void) {}

Form&	Form::operator=(const Form& src) {
	(void)src;
	return *this;
}

void		Form::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void		Form::execute(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (_gradeToExecute < executor.getGrade())
		throw GradeTooLowException();
	executeAction();
}


const std::string&	Form::getName(void) const { return _name; }
const int&			Form::getGradeToSign(void) const { return _gradeToSign; }
const int&			Form::getGradeToExecute(void) const { return _gradeToExecute; }
const bool&			Form::getSignedState(void) const { return _isSigned; }

Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException& src) { (void)src; }
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

Form::GradeTooHighException&	Form::GradeTooHighException::operator=(const GradeTooHighException& src)
{
	(void)src;
	return *this;
}

const char* 	Form::GradeTooHighException::what(void) const throw()
{
	return "The grade of the bureaucrat is too high.";
}

Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException& src) { (void)src; }
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

Form::GradeTooLowException&	Form::GradeTooLowException::operator=(const GradeTooLowException& src)
{
	(void)src;
	return *this;
}

const char* 	Form::GradeTooLowException::what(void) const throw()
{
	return "The grade of the bureaucrat is too low.";
}

Form::FormNotSignedException::FormNotSignedException(void) {}
Form::FormNotSignedException::FormNotSignedException(const FormNotSignedException& src) { (void)src; }
Form::FormNotSignedException::~FormNotSignedException(void) throw() {}

Form::FormNotSignedException&	Form::FormNotSignedException::operator=(const FormNotSignedException& src)
{
	(void)src;
	return *this;
}

const char* 	Form::FormNotSignedException::what(void) const throw()
{
	return "The form was not signed.";
}

std::ostream&	operator<<(std::ostream& o, const Form& i)
{
	o << i.getName()
		<< " form can be signed by a bureaucrat of minimum grade "
		<< i.getGradeToSign()
		<< " and executed by a bureaucrat of minimum grade "
		<< i.getGradeToExecute() << ". It's signed state is "
		<< i.getSignedState();
	return o;
}
