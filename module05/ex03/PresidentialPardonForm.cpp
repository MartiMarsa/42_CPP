	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:43:59 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/01 14:10:30 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", PGRADETOSIGN, PGRADETOEXECUTE), _target("Undefined target")
{

} 

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", PGRADETOSIGN, PGRADETOEXECUTE), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PresidentialPardonForm", PGRADETOSIGN, PGRADETOEXECUTE)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

std::string const &		PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << BLUE << "🎤✨ " << _target << " has been pardoned by Zaphod Beeblebrox! 🛸👽" << RESET << std::endl;
}

