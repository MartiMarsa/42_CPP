/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:15:49 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/15 19:15:50 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "colours.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::cout << "\nTest num 1. We're trying to find number 5 in a vector container ";
	std::cout << "that has the numbers from 1 to 10." << std::endl;
	try
	{
		std::vector<int> numbers;
		for (int i = 0; i < 10; ++i)
			numbers.push_back(i);
		int position = easyfind(numbers, 5);

		std::cout << GREEN << "The value was found in position num: " << position;
		std::cout << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Caught an exception: " << e.what() << RESET << '\n';
	}

	std::cout << "\nTest num 2. We're trying to find number 890 in a vector container ";
	std::cout << "that has the numbers from 1 to 10." << std::endl;
	try
	{
		std::vector<int> numbers;
		for (int i = 0; i < 10; ++i)
			numbers.push_back(i);
		int position = easyfind(numbers, 890);

		std::cout << GREEN << "The value was found in position num: " << position;
		std::cout << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Caught an exception: " << e.what() << RESET << '\n';
	}
	std::cout << "\nTest num 3. We're trying to find number 3 in a list container ";
	std::cout << "that has the numbers from 1 to 10." << std::endl;
	try
	{
		std::list<int>	numbers;
		for (int i = 0; i < 10; ++i)
			numbers.push_back(i);
		int position = easyfind(numbers, 3);

		std::cout << GREEN << "The value was found in position num: " << position;
		std::cout << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Caught an exception: " << e.what() << RESET << '\n';
	}
	std::cout << "\nTest num 4. We're trying to find number 666 in a list container ";
	std::cout << "that has the numbers from 1 to 10." << std::endl;
	try
	{
		std::list<int>	numbers;
		for (int i = 0; i < 10; ++i)
			numbers.push_back(i);
		int position = easyfind(numbers, 666);

		std::cout << GREEN << "The value was found in position num: " << position;
		std::cout << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Caught an exception: " << e.what() << RESET << '\n';
	}
	std::cout << BLUE << "\n Thanks for using the service. Come back soon! 😃" << RESET << std::endl;
	return(0);
}
