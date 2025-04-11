/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:06:46 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/11 15:06:47 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "realType.hpp"

Base::~Base() {}

Base *    generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	
	switch (random)
	{
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
		default: return NULL;
	}
}

void    identify(Base * p)
{
	A* a = dynamic_cast<A *>(p);
	B* b = dynamic_cast<B *>(p);
	C* c = dynamic_cast<C *>(p);
	
	if (a)
		std::cout << "p points to 'A'." << std::endl;
	else if (b)
		std::cout << "p points to 'B'." << std::endl;
	else if (c)
		std::cout << "p points to 'C'." << std::endl;
	else
		std::cout << "An error must occurred." << std::endl;
}

void	identify(Base & p)
{
	try {
		A& a =  dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Reference is 'A'.\n";
	}
	catch (std::bad_cast&) {}
	try {
		B& b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Reference is 'B'.\n";
	}
	catch (std::bad_cast&) {}
	try {
		C& c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Reference is 'C'.\n";
	}
	catch (std::bad_cast&) {}
}