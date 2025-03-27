/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:55:18 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/27 12:55:21 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, const unsigned int gradeToSign,
	const unsigned int gradeToExecute, bool ratified) : _name(name),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
	_ratified(ratified)
{
	if (_gradeToExecute < TOP_GRADE || _gradeToSign < TOP_GRADE)
		throw GradeTooHighException();
	if (_gradeToExecute > LAST_GRADE || _gradeToSign > LAST_GRADE)
		throw GradeTooLowException();
}	

Form::~Form() {}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), 
	_gradeToExecute(other._gradeToExecute), _ratified(other._ratified) {}	

Form &Form::operator=(const Form &other)
{
	(void)other;
	// does not have sense as most of the atributes are not modifiables
	return (*this);
}

std::string const &		Form::getName() const
{
	return (this->_name);
}

unsigned int		Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

unsigned int		Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}
	
bool					Form::getSigned() const
{
	return (this->_ratified);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high. Ranges are from 1 to 150.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low. Ranges are from 1 to 150.";
}

const char* Form::FormAlreadySigned::what() const throw()
{
	return "This form was already signed.";
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	return (out << GREEN << "Form Info:\nName-> " << form.getName() << "\nGrade to sign-> " <<
			form.getGradeToSign() << "\nGrade to execute-> " << form.getGradeToExecute() <<
			"\nSigned-> " << form.getSigned()) << RESET;
}

void				Form::beSigned(const Bureaucrat &Bcrat)
{
	if (Bcrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
		this->_ratified = true;
}