/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:43:59 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/31 16:44:00 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", SGRADETOSIGN, SGRADETOEXECUTE), _target("Undefined target")
{

} 

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", SGRADETOSIGN, SGRADETOEXECUTE), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 	AForm("ShrubberyCreationForm", SGRADETOSIGN, SGRADETOEXECUTE)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

std::string const &		ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::executeAction() const
{
	std::string fileName = this->getTarget() + "_shruberry";
	std::ofstream outFile(fileName.c_str());

	if (!outFile.is_open())
			throw std::runtime_error("Failed to create shruberry file.");
	
	outFile << "       _-_       " << std::endl
            << "    /~~   ~~\\   " << std::endl
            << " /~~         ~~\\" << std::endl
            << "{               }" << std::endl
            << " \\  _-     -_  /" << std::endl
            << "   ~  \\\\ //  ~ " << std::endl
            << "_- -   | | _- _  " << std::endl
            << "  _ -  | |   -_  " << std::endl
            << "      // \\\\     " << std::endl;

	outFile.close();
	std::cout << BLUE << "🌳 Shrubbery created at: " << fileName << RESET << std::endl;
}

