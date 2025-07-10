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

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include "colours.hpp"
#include "easyfind.hpp"

int main(void)
{
	// TEST 1: VECTOR - FOUND
	std::cout << YELLOW << "\n🔍 Test 1: Searching for number 5 in a vector with values 0–9." << RESET << std::endl;
	try {
		std::vector<int> vec;
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);
		int pos = easyfind(vec, 5);
		std::cout << GREEN << "✅ Found value 5 at position: " << pos << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	// TEST 2: VECTOR - NOT FOUND
	std::cout << YELLOW << "\n🔍 Test 2: Searching for number 890 in a vector with values 0–9." << RESET << std::endl;
	try {
		std::vector<int> vec;
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);
		int pos = easyfind(vec, 890);
		std::cout << GREEN << "✅ Found value 890 at position: " << pos << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	// TEST 3: LIST - FOUND
	std::cout << YELLOW << "\n🔍 Test 3: Searching for number 3 in a list with values 0–9." << RESET << std::endl;
	try {
		std::list<int> lst;
		for (int i = 0; i < 10; ++i)
			lst.push_back(i);
		int pos = easyfind(lst, 3);
		std::cout << GREEN << "✅ Found value 3 at position: " << pos << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	// TEST 4: LIST - NOT FOUND
	std::cout << YELLOW << "\n🔍 Test 4: Searching for number 666 in a list with values 0–9." << RESET << std::endl;
	try {
		std::list<int> lst;
		for (int i = 0; i < 10; ++i)
			lst.push_back(i);
		int pos = easyfind(lst, 666);
		std::cout << GREEN << "✅ Found value 666 at position: " << pos << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

	// TEST 5: DEQUE - FOUND
	std::cout << YELLOW << "\n🔍 Test 5: Searching for number 7 in a deque with values 0–9." << RESET << std::endl;
	try {
		std::deque<int> dq;
		for (int i = 0; i < 10; ++i)
			dq.push_back(i);
		int pos = easyfind(dq, 7);
		std::cout << GREEN << "✅ Found value 7 at position: " << pos << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}

// TEST 6: SET - FOUND
std::cout << YELLOW << "\n🔍 Test 6: Searching for number 4 in a set containing {4, 8, 15, 16, 23, 42}." << RESET << std::endl;
try {
	std::set<int> s;
	s.insert(4);
	s.insert(8);
	s.insert(15);
	s.insert(16);
	s.insert(23);
	s.insert(42);
	int pos = easyfind(s, 4);
	std::cout << GREEN << "✅ Found value 4 at position: " << pos << RESET << std::endl;
} catch (const std::exception& e) {
	std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
}

// TEST 7: SET - NOT FOUND
std::cout << YELLOW << "\n🔍 Test 7: Searching for number 99 in a set containing {4, 8, 15, 16, 23, 42}." << RESET << std::endl;
try {
	std::set<int> s;
	s.insert(4);
	s.insert(8);
	s.insert(15);
	s.insert(16);
	s.insert(23);
	s.insert(42);
	int pos = easyfind(s, 99);
	std::cout << GREEN << "✅ Found value 99 at position: " << pos << RESET << std::endl;
} catch (const std::exception& e) {
	std::cerr << RED << "❌ Exception: " << e.what() << RESET << std::endl;
}


	std::cout << BLUE << "\n✅ All tests completed successfully!\n" << RESET;
	std::cout << BLUE << "\n Thanks for using the service. Come back soon! 😃" << RESET << std::endl;
	return(0);
}
