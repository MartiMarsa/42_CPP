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
		std::cerr << "Caught an exeption " << e.what() << '\n';
	}
	return (0);
}
