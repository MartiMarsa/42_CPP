/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:44:55 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/24 15:44:56 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe	pm;

    if (argc > 1)
    {
		try
		{
			pm.parseArgs(argc, argv);
			std::cout << "VECTOR: ";
			for (std::vector<int>::const_iterator it = pm.getVector().begin(); it != pm.getVector().end(); ++it)
			{
				std::cout << *it << " ";
			}
			std::cout << "\nDEQUE: ";
			for (std::deque<int>::const_iterator it = pm.getDeque().begin(); it != pm.getDeque().end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
			pm.mergeInsertionSort();
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Caught an exception: " << e.what() << RESET << '\n';
		}
    }
    else
    {
        std::cout << "Please introduce correct arguments." << std::endl;
    }
     return 0;
}