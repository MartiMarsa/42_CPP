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
#include <vector>
#include <list>
#include <ctime>     // for time()
#include <cstdlib>   // for rand()

// Utility to generate random std::vector<int>
std::vector<int> generateRandomVector(int size, int minValue, int maxValue) {
	std::vector<int> v;
	for (int i = 0; i < size; ++i)
		v.push_back(minValue + rand() % (maxValue - minValue + 1));
	return v;
}

// Utility to generate random std::list<int>
std::list<int> generateRandomList(int size, int minValue, int maxValue) {
	std::list<int> lst;
	for (int i = 0; i < size; ++i)
		lst.push_back(minValue + rand() % (maxValue - minValue + 1));
	return lst;
}

int	main(void)
{
	srand(time(NULL)); // Seed RNG once

	std::cout << GREEN << "TEST 1: Filling Span with sequential values from 0 to 9 (vector).\n" << RESET;
	try {
		Span numbers(10);
		for (int i = 0; i < 10; ++i)
			numbers.addNumber(i);
		std::cout << CYAN << "✅ Shortest span: " << numbers.shortestSpan() << std::endl;
		std::cout << "✅ Longest span: " << numbers.longestSpan() << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\nTEST 2: Attempting to add a number to a Span of size 0.\n" << RESET;
	try {
		Span numbers(0);
		numbers.addNumber(1);
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\nTEST 3: Adding 10,000 values to a Span using vector and range overload.\n" << RESET;
	try {
		Span numbers(10000);
		std::vector<int> big(10000);
		for (int i = 0; i < 10000; ++i)
			big[i] = i;
		numbers.addNumber(big.begin(), big.end());
		std::cout << CYAN << "✅ Shortest span: " << numbers.shortestSpan() << std::endl;
		std::cout << "✅ Longest span: " << numbers.longestSpan() << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\nTEST 4: Filling Span with 100 random values (vector).\n" << RESET;
	try {
		Span numbers(100);
		std::vector<int> randVec = generateRandomVector(100, 0, 100000);
		numbers.addNumber(randVec.begin(), randVec.end());
		std::cout << CYAN << "✅ Shortest span: " << numbers.shortestSpan() << std::endl;
		std::cout << "✅ Longest span: " << numbers.longestSpan() << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\nTEST 5: Attempting to calculate spans on an empty Span.\n" << RESET;
	try {
		Span numbers(10);
		std::cout << "Shortest span: " << numbers.shortestSpan() << std::endl;
		std::cout << "Longest span: " << numbers.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\nTEST 6: Using std::list<int> with random values to test template range.\n" << RESET;
	try {
		Span numbers(50);
		std::list<int> randList = generateRandomList(50, 0, 1000);
		numbers.addNumber(randList.begin(), randList.end());
		std::cout << CYAN << "✅ Shortest span: " << numbers.shortestSpan() << std::endl;
		std::cout << "✅ Longest span: " << numbers.longestSpan() << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\nTEST 7: Add only one number and try to compute span.\n" << RESET;
	try {
		Span numbers(5);
		numbers.addNumber(42);
		std::cout << "Shortest span: " << numbers.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "✔️ Caught expected exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\nTEST 8: Try to overflow Span capacity.\n" << RESET;
	try {
		Span numbers(3);
		numbers.addNumber(10);
		numbers.addNumber(20);
		numbers.addNumber(30);
		std::cout << "Attempting to add a 4th number...\n";
		numbers.addNumber(40); // should throw
		std::cout << RED << "❌ Error: No exception thrown when overflowing." << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "✔️ Caught expected exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\nTEST 9: Use negative and unordered values.\n" << RESET;
	try {
		Span numbers(5);
		numbers.addNumber(-100);
		numbers.addNumber(200);
		numbers.addNumber(0);
		numbers.addNumber(42);
		numbers.addNumber(-50);
		std::cout << "✅ Shortest span: " << CYAN << numbers.shortestSpan() << RESET << std::endl;
		std::cout << "✅ Longest span:  " << CYAN << numbers.longestSpan() << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Error: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\nTEST 10: Massive random test with 50,000 numbers.\n" << RESET;
	try {
		Span numbers(50000);
		std::vector<int> large = generateRandomVector(50000, 0, 1000000);
		numbers.addNumber(large.begin(), large.end());
		std::cout << "✅ Shortest span: " << CYAN << numbers.shortestSpan() << RESET << std::endl;
		std::cout << "✅ Longest span:  " << CYAN << numbers.longestSpan() << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Error: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n✅ All tests completed successfully!\n" << RESET;
	std::cout << BLUE << "\n Thanks for using the service. Come back soon! 😃" << RESET << std::endl;
	return (0);
}
