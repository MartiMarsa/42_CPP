/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:03:49 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/14 18:03:51 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int> roulette(5);
	try
	{
		for (unsigned int i = 0; i != roulette.size(); ++i)
		{
			int number = rand();
			roulette[i] = number;
		}
		std::cout << roulette << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught an exeption: " << e.what() << '\n';
	}
	try
	{
		std::cout << "We're trying to access to index 10.\n" << roulette[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught an exeption: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "We're trying to access an index less than 0.\n" << roulette[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught an exeption: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\nWe're trying to instantiate the object with copy assignment." << std::endl;
		Array<int> tmp = roulette;
		std::cout << tmp << std::endl;
		std::cout << "We're trying to intantiate the object with the copy constructor." << std::endl;
		Array<int> copy(tmp);
		std::cout << copy << std::endl;

		std::cout << "Those are the pointers to each object:\n";
		std::cout << "Roulette -> "<< roulette.getRawPointer() << std::endl;
		std::cout << "tmp -> "<< tmp.getRawPointer() << std::endl;
		std::cout << "copy -> "<< copy.getRawPointer() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
