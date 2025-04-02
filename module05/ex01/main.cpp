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
#include "Form.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	std::cout << "TEST Num 1" << std::endl;
	try 
	{
		Form f1("Divorce", 10, 5);
		std::cout << f1 << "\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}
		std::cout << "TEST Num 2" << std::endl;
	try 
	{
		Bureaucrat b2("François Leclerc", 5);
		std::cout << b2 << std::endl;
		Form f1("Mortgage", 5, 5);
		std::cout << f1 << std::endl;
		b2.signForm(f1);
		std::cout << f1 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}
		std::cout << "TEST Num 3" << std::endl;
		try 
	{
		Bureaucrat b2("Louis Gérard", 10);
		std::cout << b2 << std::endl;
		Form f1("Loan", 5, 5);
		std::cout << f1 << std::endl;
		b2.signForm(f1);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}

	std::cout << "TEST Num 4" << std::endl;
	try 
	{
		Form f1("Alien hunting", 0, 5);
		std::cout << f1 << "\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << "Caught an exception " << e.what() << RESET <<  std::endl;
	}
	return (0);
}