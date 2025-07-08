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

int	main(void)
{
	std::cout << "TEST num 1. Is a vector that stores a maximum of 10 integers from ";
	std::cout << "0 to 9.\n";

	try
	{
		Span numbers(10);
		for (int i = 0; i < 10; ++i)
		{
			numbers.addNumber(i);
			std::cout << numbers.getNumberAt(i) << std::endl;
		}
		std::cout << "Shortest span is " << numbers.shortestSpan() << std::endl;
		std::cout << "Longest span is " << numbers.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught an exception. " << e.what() << '\n';
	}
	try
	{
		Span numbers(0);
		numbers.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught an exception. " << e.what() << '\n';
	}
	
	return (0);
}
