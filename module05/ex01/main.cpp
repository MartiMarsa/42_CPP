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

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	std::cout << "TEST Num 1" << std::endl;
	try 
	{
		std::cout << GREEN;
		Bureaucrat b1("Jean Dupont", 0);
		std::cout << "This is not going to print" << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}
		std::cout << '\n' << "TEST Num 2" << std::endl;
	try 
	{
		std::cout << GREEN;
		Bureaucrat b2("François Leclerc", 5);
		std::cout << b2 << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}
			std::cout << '\n' << "TEST Num 3" << std::endl;
	try 
	{
		std::cout << GREEN;
		Bureaucrat b3("Louis Gérard", 151);
		std::cout << b3 << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}
			std::cout << '\n' << "TEST Num 4" << std::endl;
	try 
	{
		std::cout << GREEN;
		Bureaucrat b3("Louis Gérard", 100);
		std::cout << b3 << std::endl;
		b3.upGrade();
		std::cout << b3 << std::endl;
		b3.downGrade();
		std::cout << b3 << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}
		std::cout << '\n' << "TEST Num 5" << std::endl;
	try 
	{
		std::cout << GREEN;
		Bureaucrat b1("Jean Dupont", 1);
		b1.upGrade();
		std::cout << "This is not going to print" << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}
			std::cout << '\n' << "TEST Num 6" << std::endl;
	try 
	{
		std::cout << GREEN;
		Bureaucrat b1("Jean Dupont", 150);
		b1.downGrade();
		std::cout << "This is not going to print" << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}
	return (0);
}