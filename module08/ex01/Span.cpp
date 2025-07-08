/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:52:04 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/16 16:52:06 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _numbers(0) {}

Span::Span(unsigned int N) : _N(N), _numbers(0) {}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int num)
{
	if (this->_numbers.size() == this->_N)
		throw std::runtime_error("Cannot add more numbers");
	this->_numbers.push_back(num);
}

int		Span::shortestSpan()
{
	int ss = INT_MAX;
	std::vector<int> sorted = this->_numbers;

	if (sorted.size() <= 1)
		throw std::runtime_error("Not enough numbers to find span.");
	std::sort(sorted.begin(), sorted.end());
	for (unsigned int i = 0; i < sorted.size() - 1; ++i)
	{
		if (ss > (sorted[i + 1] - sorted[i]))
		{
			ss = sorted[i + 1] - sorted[i];
		}
	}
	return (ss);
}

int		Span::longestSpan()
{
	if (this->_numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers to find span.");
	std::vector<int>::iterator	itMax = std::max_element(this->_numbers.begin(),
															this->_numbers.end());
	std::vector<int>::iterator	itMin = std::min_element(this->_numbers.begin(),
															this->_numbers.end());
	int	max = *itMax;
	int min = *itMin;
	return (max - min);
}


const std::vector<int> &	Span::getNumbers() const
{
	return _numbers;
}

int							Span::getNumberAt(int index) const
{
	return _numbers[index];
}