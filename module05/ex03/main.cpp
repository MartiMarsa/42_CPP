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
#include "Intern.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

		std::cout << "\nTEST Num 1" << std::endl;
	try 
	{
		Bureaucrat				Bc1("🐱 Beerus-sama", 1);
		Intern					RandomStronzo;
		std::cout << Bc1 << "\n" << std::endl;
		AForm* P1 = RandomStronzo.makeForm("presidential pardon", "Abalos");
		std::cout << P1->getName() << "\n" << std::endl;
		P1->beSigned(Bc1);
		P1->execute(Bc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "⛔ Caught an exception: " << e.what() << RESET <<  std::endl;
	}
	std::cout << "\nTEST Num 2.0" << std::endl;
	try 
	{
		Bureaucrat				Bc1("John Connor", 80);
		Intern					RandomStronzo;
		std::cout << Bc1 << "\n" << std::endl;
		AForm* P1 = RandomStronzo.makeForm("robotomy request", "Skynet");
		std::cout << P1->getName() << "\n" << std::endl;
		P1->beSigned(Bc1);
		P1->execute(Bc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "⛔ Caught an exception: " << e.what() << RESET <<  std::endl;
	}
	std::cout << "\nTEST Num 2.1" << std::endl;
	try 
	{
		Bureaucrat				Bc1("John Connor", 70);
		Intern					RandomStronzo;
		std::cout << Bc1 << "\n" << std::endl;
		AForm* P1 = RandomStronzo.makeForm("robotomy request", "Skynet");
		std::cout << P1->getName() << "\n" << std::endl;
		P1->beSigned(Bc1);
		P1->execute(Bc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "⛔ Caught an exception: " << e.what() << RESET <<  std::endl;
	}
	std::cout << "\nTEST Num 2.2" << std::endl;
	try 
	{
		Bureaucrat				Bc1("John Connor", 30);
		Intern					RandomStronzo;
		std::cout << Bc1 << "\n" << std::endl;
		AForm* P1 = RandomStronzo.makeForm("robotomy request", "Skynet");
		std::cout << P1->getName() << "\n" << std::endl;
		P1->beSigned(Bc1);
		P1->execute(Bc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "⛔ Caught an exception: " << e.what() << RESET <<  std::endl;
	}
		std::cout << "\nTEST Num 3.0" << std::endl;
	try 
	{
		Bureaucrat				Bc1("Willy the Janitor", 100);
		Intern					RandomStronzo;
		std::cout << Bc1 << "\n" << std::endl;
		AForm* P1 = RandomStronzo.makeForm("shrubbery creation", "Ralph");
		std::cout << P1->getName() << "\n" << std::endl;
		P1->beSigned(Bc1);
		P1->execute(Bc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "⛔ Caught an exception: " << e.what() << RESET <<  std::endl;
	}
		std::cout << "\nTEST Num 4.0" << std::endl;
		try 
	{
		Bureaucrat				Bc1("Pa amb tomaquet", 100);
		Intern					RandomStronzo;
		std::cout << Bc1 << "\n" << std::endl;
		AForm* P1 = RandomStronzo.makeForm("espetec casa tarradellas", "granny");
		std::cout << P1->getName() << "\n" << std::endl;
		P1->beSigned(Bc1);
		P1->execute(Bc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "⛔ Caught an exception: " << e.what() << RESET <<  std::endl;
	}
}