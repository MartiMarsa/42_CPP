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

void PmergeMe::parseArgs(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error: No arguments provided");
	if (argc == 2) {
		std::stringstream ss(argv[1]);
		std::string token;
		while (ss >> token) {
			processToken(token);
		}
	}
	else {
		for (int i = 1; i < argc; i++) {
			processToken(argv[i]);
		}
	}
	detectDuplicates(_vector);
	detectDuplicates(_deque);
	_originalVector = _vector;
	_originalDeque = _deque;
}

void PmergeMe::processToken(const std::string& token)
{
	long long int num = 0;
	if (!ft_isDigit(token.at(0)))
		throw std::runtime_error("Error: Non-digit character found");
	if (token.size() > 10 || !ft_strToLL(token, num))
		throw std::runtime_error("Error: Invalid number format or overflow");
	if (num > 0 && num <= INT_MAX)
	{
		_vector.push_back(num);
		_deque.push_back(num);
	}
	else
		throw std::runtime_error("Error: Invalid number format or overflow");
}

std::vector<int>	PmergeMe::jacobsthalGenerator(int i)
{
	std::vector<int>	jacobSequence;
	jacobSequence.push_back(0);
	jacobSequence.push_back(1);
	while (jacobSequence.back() <= i)
	{
		int n = jacobSequence[jacobSequence.size() - 1] + 2 * jacobSequence[jacobSequence.size() - 2];
		jacobSequence.push_back(n);
	}
	return jacobSequence;
}

/********************************************\
|*           🃏  D E Q U E  🃏            *|
\********************************************/

void	PmergeMe::binaryInsert(std::deque<int> & arr, int num)
{
	int	left = 0;
	int	right = arr.size() - 1;
	while (left <= right)
	{
		int	mid = left + (right - left) / 2;
		if (arr[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;
	}
	arr.insert(arr.begin() + left, num);
}

void PmergeMe::insertLosers(std::deque<int>& winners, std::deque<int>& losers)
{
	if (losers.size() <= 1)
		return;
	std::vector<int> jS = jacobsthalGenerator(losers.size());
	std::vector<bool> inserted(losers.size(), false);
	for (size_t m = jS.size() - 1; m >= 1 && m < jS.size(); --m) {
		int step = jS[m];
		for (int i = step - 1; i < static_cast<int>(losers.size()); i += step)
		{
			if (!inserted[i])
			{
				binaryInsert(winners, losers[i]);
				inserted[i] = true;
			}
		}
	}
	for (size_t i = 0; i < losers.size(); ++i)
	{
		if (!inserted[i])
			binaryInsert(winners, losers[i]);
	}
}

void	PmergeMe::mergeInsertionSort(std::deque<int> & arr)
{
	if (arr.empty())
		throw std::runtime_error("Error: empty input.");
	if (arr.size() < 2)
		return;
	
	int odd = -1;
	if (arr.size() % 2 != 0)
	{
		odd = arr.back();
		arr.pop_back();
	}
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 < arr.size())
			pairs.push_back(std::make_pair(arr[i], arr[i+1]));
	}
	std::deque<int>	winners;
	std::deque<int>	losers;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first < pairs[i].second)
		{
			winners.push_back(pairs[i].second);
			losers.push_back(pairs[i].first);
		} else
		{
			winners.push_back(pairs[i].first);
			losers.push_back(pairs[i].second);
		}
	}
	mergeInsertionSort(winners);
	if (!losers.empty() && winners.size() < 2)
		binaryInsert(winners, losers[0]);
	insertLosers(winners, losers);
	if (odd != -1)
		binaryInsert(winners, odd);
	arr = winners;
}

/********************************************\
|*           🚀  V E C T O R  🚀          *|
\********************************************/

void	PmergeMe::binaryInsert(std::vector<int> & arr, int num)
{
	int	left = 0;
	int	right = arr.size() - 1;
	while (left <= right)
	{
		int	mid = left + (right - left) / 2;
		if (arr[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;
	}
	arr.insert(arr.begin() + left, num);
}

void PmergeMe::insertLosers(std::vector<int> &winners, std::vector<int> &losers)
{
	if (losers.size() <= 1)
		return;
	std::vector<int> jS = jacobsthalGenerator(losers.size());
	std::vector<bool> inserted(losers.size(), false);
	for (size_t m = jS.size() - 1; m >= 1 && m < jS.size(); --m) {
		int step = jS[m];
		for (int i = step - 1; i < static_cast<int>(losers.size()); i += step)
		{
			if (!inserted[i])
			{
				binaryInsert(winners, losers[i]);
				inserted[i] = true;
			}
		}
	}
	for (size_t i = 0; i < losers.size(); ++i)
	{
		if (!inserted[i])
			binaryInsert(winners, losers[i]);
	}
}

void PmergeMe::mergeInsertionSort(std::vector<int> &arr)
{
	if (arr.size() < 2)
		return;
	int odd = -1;
	if (arr.size() % 2 != 0)
	{
		odd = arr.back();
		arr.pop_back();
	}
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 < arr.size())
			pairs.push_back(std::make_pair(arr[i], arr[i+1]));
	}
	std::vector<int>	winners;
	std::vector<int>	losers;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first < pairs[i].second)
		{
			winners.push_back(pairs[i].second);
			losers.push_back(pairs[i].first);
		} else
		{
			winners.push_back(pairs[i].first);
			losers.push_back(pairs[i].second);
		}
	}
	mergeInsertionSort(winners);
	if (!losers.empty() && winners.size() < 2)
		binaryInsert(winners, losers[0]);
	insertLosers(winners, losers);
	if (odd != -1)
		binaryInsert(winners, odd);
	arr = winners;
}

std::vector<int> &PmergeMe::getVector() { return this->_vector; }

std::deque<int> &PmergeMe::getDeque() { return this->_deque; }

std::vector<int> 	&PmergeMe::getOriginalVector() {return this->_originalVector; }

std::deque<int>		&PmergeMe::getOriginalDeque() { return this->_originalDeque; }

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