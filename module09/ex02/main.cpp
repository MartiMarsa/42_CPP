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
			pm.doSorting();
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