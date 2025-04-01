/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:36:10 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/01 17:36:11 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

const char* Intern::NoFormExeption::what() const throw ()
{
	return "This form is not avaiable.";
}

AForm*  Intern::makeForm(std::string formName, std::string formTarget)
{
	std::map< std::string, AForm* (Intern::*)(std::string) > forMap;
	forMap["shrubbery creation"] = &Intern::makeShubbery;
	forMap["robotomy request"] = &Intern::makeRobotomy;
	forMap["presidential pardon"] = &Intern::makePresidential;

	std::map< std::string, AForm* (Intern::*)(std::string) >::iterator it = forMap.find(formName);
	if (it != forMap.end())
		return (this->*(it->second))(formTarget);
	else
		throw NoFormExeption();
}

AForm*	Intern::makeShubbery(std::string formTarget)
{
	std::cout << YELLOW << "Intern creates a form for: " << formTarget << RESET << std::endl;
	return (new ShrubberyCreationForm(formTarget));
}

AForm*	Intern::makeRobotomy(std::string formTarget)
{
	std::cout << YELLOW << "Intern creates a form for: " << formTarget << RESET << std::endl;
	return (new RobotomyRequestForm(formTarget));
}

AForm*	Intern::makePresidential(std::string formTarget)
{
	std::cout << YELLOW << "Intern creates a form for: " << formTarget << RESET << std::endl;
	return (new PresidentialPardonForm(formTarget));
}