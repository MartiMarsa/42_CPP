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

void	PmergeMe::detectDuplicates(const std::vector<int> &vector)
{
	std::set<int>		uniqueElements;
	std::vector<int>	temp;
	std::vector<int>::const_iterator	it = vector.begin();
	for (; it != vector.end(); ++it)
	{
		if (uniqueElements.insert(*it).second)
			temp.push_back(*it);
		else
			throw std::runtime_error("Error: duplicate found.");
	}
	_vector.swap(temp);
}

void	PmergeMe::detectDuplicates(const std::deque<int> &deque)
{
	std::set<int>	uniqueElements;
	std::deque<int> temp;
	std::deque<int>::const_iterator	it = deque.begin();
	for (; it != deque.end(); ++it)
	{
		if (uniqueElements.insert(*it).second)
			temp.push_back(*it);
		else
			throw std::runtime_error("Error: duplicate found.");
	}
	_deque.swap(temp);
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
					throw std::runtime_error("Error: bad input. This program accepts an array of positive integers");
				_vector.push_back(num);
				_deque.push_back(num);
			}
			else
				throw std::runtime_error("Error: bad input. This program accepts an array of positive integers");
		}
		detectDuplicates(_vector);
		detectDuplicates(_deque);
	}
}

void	PmergeMe::doSorting() {}

const std::vector<int> &PmergeMe::getVector() const { return this->_vector; }

const std::deque<int> &PmergeMe::getDeque() const { return this->_deque; }

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
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}