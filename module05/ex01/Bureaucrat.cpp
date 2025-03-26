/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:41:39 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/26 15:41:40 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name),
_grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// this->_name = other._name; -> cannot change a const std::string
		this->_grade = other._grade;
	}
	return (*this);
}

std::string const &	Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::upGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		--_grade;
}

void	Bureaucrat::downGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high. Ranges are from 1 to 150.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low. Ranges are from 1 to 150.";
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &Bcrat)
{
	return out << Bcrat.getName() << ", bureaucrat " << Bcrat.getGrade() << ".";
}
