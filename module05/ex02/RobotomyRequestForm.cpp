/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:43:59 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/31 16:44:00 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", RGRADETOSIGN, RGRADETOEXECUTE), _target("Undefined target")
{

} 

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", RGRADETOSIGN, RGRADETOEXECUTE), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm", RGRADETOSIGN, RGRADETOEXECUTE)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

std::string const &		RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << BLUE << "🔧 *Drilling noises* 🔧" << RESET << std::endl;
	
	std::srand(std::time(0));
	if (std::rand() % 2)
	    std::cout << BLUE << "🤖 " << _target << " has been successfully robotomized!" << RESET <<std::endl;
	else
	    std::cout << YELLOW << "❌ Robotomy failed for " << _target << "!" << RESET << std::endl;
	
}

