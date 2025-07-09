/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:35:23 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/16 18:35:24 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "../ex00/colours.hpp"

std::vector<int> generateRandomVector(int size, int minValue, int maxValue) {
	std::vector<int> v;

	for (int i = 0; i < size; ++i) {
		int n = minValue + rand() % (maxValue - minValue + 1);
		v.push_back(n);
	}

	return v;
}

int	main(void)
{
	std::cout << GREEN << "TEST num 1. Is a vector that stores a maximum of 10 integers from ";
	std::cout << "0 to 9.\n" << RESET;

	try
	{
		Span numbers(10);
		for (int i = 0; i < 10; ++i)
			numbers.addNumber(i);
		std::cout << "Shortest span is " << numbers.shortestSpan() << std::endl;
		std::cout << "Longest span is " << numbers.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught an exception. " << e.what() << '\n';
	}

	std::cout << GREEN << "\nTEST num 2. We use addnumber() in a 0 size vector.\n" << RESET;
	try
	{
		Span numbers(0);
		numbers.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Caught an exception. " << e.what() << '\n' << RESET;
	}
	
	std::cout << GREEN << "\nTEST num 3. We use addnumber() overload to add 10000 numbers from ";
	std::cout << "0 to 9999.\n" << RESET;

	try
	{
		Span numbers(10000);
		std::vector<int> bigPapa(10000);
		for (size_t i = 0; i < bigPapa.size(); ++i)
			bigPapa.at(i) = i;
		numbers.addNumber(bigPapa.begin(), bigPapa.end());
		
		std::cout << "Shortest span is " << numbers.shortestSpan() << std::endl;
		std::cout << "Longest span is " << numbers.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught an exception. " << e.what() << '\n';
	}

	std::cout << GREEN << "\nTest num 4. We generate a size 100 vector with random and unordered numbers ";
	std::cout << "from 0 to 1000000.\n" << RESET;

	try
	{
		Span numbers(100);
		std::vector<int> random = generateRandomVector(100, 0, 1000000);
		numbers.addNumber(random.begin(), random.end());

		std::cout << "Shortest span is " << numbers.shortestSpan() << std::endl;
		std::cout << "Longest span is " << numbers.longestSpan() << std::endl;
	}
	
	catch(const std::exception& e)
	{
		std::cerr << "Caught an exception. " << e.what() << '\n';
	}

	std::cout << GREEN << "\nTEST num 5. Try to find span in an empty vector.\n" << RESET;

	try
	{
		Span numbers(10);

		std::cout << "Shortest span is " << numbers.shortestSpan() << std::endl;
		std::cout << "Longest span is " << numbers.longestSpan() << std::endl;
	}

	catch(const std::exception& e)
	{
		std::cerr << RED << "Caught an exception. " << e.what() << '\n';
	}

	return (0);
}
