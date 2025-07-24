/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:45:53 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/24 15:45:54 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		;
	return *this;
}

void	PmergeMe::parseArgs(int argc, char **argv)
{
	if (argc == 2)
	{
		std::stringstream	ss(argv[1]);
		std::string			token;
		while (ss >> token)
		{
			long long int	num = 0;
			if (ft_isDigit(token.at(0)))
			{
				if (token.size() > 10 || !ft_strToLL(token, num))
				{
					std::cerr << "Error: bad input. This program accepts an array of positive integers" << std::endl;
				}
			}
		}
	}
}

void	PmergeMe::doSorting() {}

bool	ft_isDigit(char c)
{
	if (c >= 48 && c <= 57)
	{
		return true;
	}
	return false;
}

bool	ft_strToLL(const std::string & str, long long int &num)
{
	std::stringstream	ss(str);

	ss >> num;
	if (ss.fail() || ss.eof())
		return false;
	return true;
}