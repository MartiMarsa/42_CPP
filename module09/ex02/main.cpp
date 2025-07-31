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
			struct timeval start, end;
			gettimeofday(&start, NULL);
			pm.parseArgs(argc, argv);
			gettimeofday(&end, NULL);
			double	time = (end.tv_sec = start.tv_sec) + (end.tv_usec - start.tv_usec);
			std::cout << "Before: ";
			int print_limit = std::min(20, static_cast<int>(pm.getVector().size()));
			for (int i = 0; i < print_limit; ++i) 
			{
				std::cout << pm.getVector()[i] << " ";
			}
			std::cout << std::endl;

			/********************************************\
			|*           🚀  V E C T O R  🚀          *|
			\********************************************/

			struct timeval vecStart, vecEnd;
			gettimeofday(&vecStart, NULL);
			pm.mergeInsertionSort(pm.getVector());
			gettimeofday(&vecEnd, NULL);
			double vecTime = (vecEnd.tv_sec - vecStart.tv_sec) * 1000000.0 + (vecEnd.tv_usec - vecStart.tv_usec) + time/1000000;

			/********************************************\
			|*           🃏  D E Q U E  🃏            *|
			\********************************************/

			struct timeval deqStart, deqEnd;
			gettimeofday(&deqStart, NULL);
			pm.mergeInsertionSort(pm.getDeque());
			gettimeofday(&deqEnd, NULL);
			double deqTime = (deqEnd.tv_sec - deqStart.tv_sec) * 1000000.0 + (deqEnd.tv_usec - deqStart.tv_usec) + time/1000000;
			
			std::cout << "After: ";
			for (int i = 0; i < print_limit; ++i) 
			{
				std::cout << pm.getVector()[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Time to process a range of " << pm.getOriginalVector().size() << " elements with std::vector : " << std::fixed << std::setprecision(3) << vecTime/1000 << " ms" << std::endl;
			std::cout << "Time to process a range of " << pm.getOriginalDeque().size() << " elements with std::deque : " << std::fixed << std::setprecision(3) << deqTime/1000 << " ms" << std::endl;
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