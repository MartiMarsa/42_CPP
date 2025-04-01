/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:30:49 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/01 17:30:51 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <map>
# include <exception>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other); 
		~Intern();

		AForm*	makeForm(std::string formName, std::string formTarget);
		AForm*	makeShubbery(std::string formName);
		AForm*	makeRobotomy(std::string formName);
		AForm*	makePresidential(std::string formName);

		class	NoFormExeption : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
