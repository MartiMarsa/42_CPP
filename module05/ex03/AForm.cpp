/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:55:18 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/27 12:55:21 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, const unsigned int gradeToSign,
	const unsigned int gradeToExecute) : _name(name),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
	_ratified(0)
{
	if (_gradeToExecute < TOP_GRADE || _gradeToSign < TOP_GRADE)
		throw GradeTooHighException();
	if (_gradeToExecute > LAST_GRADE || _gradeToSign > LAST_GRADE)
		throw GradeTooLowException();
}	

AForm::~AForm() {}

AForm::AForm(const AForm &other) : _name(other._name), _gradeToSign(other._gradeToSign), 
	_gradeToExecute(other._gradeToExecute), _ratified(other._ratified) {}	

AForm &AForm::operator=(const AForm &other)
{
	(void)other;
	// does not have sense as most of the atributes are not modifiables
	return (*this);
}

std::string const &		AForm::getName() const
{
	return (this->_name);
}

unsigned int		AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

unsigned int		AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}
	
bool					AForm::getSigned() const
{
	return (this->_ratified);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high. Ranges are from 1 to 150.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low to proceed";
}

const char* AForm::AFormAlreadySigned::what() const throw()
{
	return "This Aform was already signed.";
}

const char* AForm::AFormNotSigned::what() const throw()
{
	return "This form is not signed yet.";
}

std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	return (out << GREEN << "AForm Info:\nName-> " << form.getName() << "\nGrade to sign-> " <<
			form.getGradeToSign() << "\nGrade to execute-> " << form.getGradeToExecute() <<
			"\nSigned-> " << form.getSigned()) << RESET;
}

void				AForm::beSigned(const Bureaucrat &Bcrat)
{
	if (Bcrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
	{
		this->_ratified = true;
		std::cout << BLUE << Bcrat.getName() <<" Signed " << this->getName() << " like a boss.\n" << RESET <<std::endl;
	}
}

void				AForm::execute(const Bureaucrat & executor) const
{
	if (!_ratified)
		throw AFormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	this->executeAction();
}