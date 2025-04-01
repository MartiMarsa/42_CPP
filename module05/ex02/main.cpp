/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:24:29 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/26 17:24:31 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	std::cout << "\nTEST Num 1.0" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Gardener", 50);
		ShrubberyCreationForm	S1("Garden");
		std::cout << Bc1 << "\n" << std::endl;
		std::cout << S1 << "\n" << std::endl;
		S1.beSigned(Bc1);
		std::cout << S1 << "\n" << std::endl;
		S1.execute(Bc1);
		Bc1.executeForm(S1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
	std::cout << "\nTEST Num 1.1" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Janitor", 149);
		ShrubberyCreationForm	S1("Garden");
		std::cout << Bc1 << "\n" << std::endl;
		std::cout << S1 << "\n" << std::endl;
		S1.beSigned(Bc1);
		std::cout << S1 << "\n" << std::endl;
		S1.execute(Bc1);
		Bc1.executeForm(S1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}

	std::cout << "\nTEST Num 2.0" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Sarah Connor", 40);
		std::cout << Bc1 << "\n" << std::endl;
		RobotomyRequestForm R1("Terminator");
		std::cout << R1 << "\n" << std::endl;
		R1.beSigned(Bc1);
		std::cout << R1 << "\n" << std::endl;
		R1.execute(Bc1);
		Bc1.executeForm(R1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
		std::cout << "\nTEST Num 2.1" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Torrente", 45);
		std::cout << Bc1 << "\n" << std::endl;
		RobotomyRequestForm R1("Trashinator");
		std::cout << R1 << "\n" << std::endl;
		R1.execute(Bc1);
		Bc1.executeForm(R1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
	std::cout << "\nTEST Num 3.0" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Mariano Rajoy", 66);
		std::cout << Bc1 << "\n" << std::endl;
		PresidentialPardonForm P1("Mr. Smith");
		std::cout << P1 << "\n" << std::endl;
		P1.execute(Bc1);
		Bc1.executeForm(P1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
		std::cout << "\nTEST Num 3.1" << std::endl;
	try 
	{
		Bureaucrat				Bc1("🐱 Beerus-sama", 1);
		std::cout << Bc1 << "\n" << std::endl;
		PresidentialPardonForm P1("Mr. Smith");
		std::cout << P1 << "\n" << std::endl;
		P1.beSigned(Bc1);
		P1.execute(Bc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception: " << e.what() << RESET <<  std::endl;
	}
}