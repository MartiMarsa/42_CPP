/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:02:10 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/09 18:02:11 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "../ex00/colours.hpp"
#include <list>
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	std::cout << BLUE << "\n📦 MY MUTANT STACK USAGE\n" << RESET;
	std::cout << CYAN << "-----------------------------\n" << RESET;

	mstack.push(5);
	mstack.push(17);
	std::cout << GREEN << "Top element: " << RESET << mstack.top() << std::endl;

	mstack.pop();
	std::cout << GREEN << "Size after pop: " << RESET << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << YELLOW << "\n🔁 ITERATING THE STACK:\n" << RESET;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << YELLOW << "\n🔁 REVERSE ITERATING THE STACK:\n" << RESET;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::stack<int> s(mstack);

	// std::list test for comparison
	std::cout << MAGENTA << "\n📄 COMPARISON WITH std::list\n" << RESET;
	std::cout << CYAN << "-----------------------------\n" << RESET;

	std::list<int> ml;
	ml.push_front(5);
	ml.push_front(17);
	std::cout << GREEN << "Front element: " << RESET << ml.front() << std::endl;

	ml.pop_front();
	std::cout << GREEN << "Size after pop: " << RESET << ml.size() << std::endl;

	ml.push_back(3);
	ml.push_back(5);
	ml.push_back(737);
	ml.push_back(0);

	std::cout << YELLOW << "\n🔁 ITERATING THE LIST:\n" << RESET;
	std::list<int>::iterator lit = ml.begin();
	std::list<int>::iterator lite = ml.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << YELLOW << "\n🔁 REVERSE ITERATING THE LIST:\n" << RESET;
	std::list<int>::reverse_iterator lrit = ml.rbegin();
	std::list<int>::reverse_iterator lrite = ml.rend();
	++lrit;
	--lrit;
	while (lrit != lrite)
	{
		std::cout << *lrit << std::endl;
		++lrit;
	}

	std::cout << BLUE << "\n✅ All tests completed successfully!\n" << RESET;
	std::cout << BLUE << "\n Thanks for using the service. Come back soon! 😃" << RESET << std::endl;
	return 0;
}
