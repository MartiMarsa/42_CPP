/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:30:36 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/17 19:30:40 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

bool	ft_strToLL(const std::string &token, long long int &num)
{
	std::stringstream	ss(token);

	ss >> num;
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

bool    RPN::isAllowedCharacter(const std::string & input)
{
    for (size_t i = 0; i != input.size(); ++i)
    {
        if (!ft_isDigit(input.at(i)) && !ft_isOperator(input.at(i)) && !ft_isSpace(input.at(i)))
			return false;
    }
	return true;
}

bool    RPN::validateInput(const std::string & input)
{
    if (input.empty())
        return false;
    if (!isAllowedCharacter(input))
        return false;
	else
		return true;
}

void    RPN::reversePolishNotation(const std::string & input)
{
	std::stringstream	ss(input);
    std::string			token;
    
	while (ss >> token)
	{
		long long int		num = 0;
		long long int		operant_a = 0;
		long long int		operant_b = 0;

		if (ft_isDigit(token.at(0)))
		{
			if (!ft_strToLL(token, num))
				std::cerr << "Shit happened." << std::endl;
			_stack.push(num);
		}
		if (ft_isOperator(token.at(0)))
		{
			if (token.at(0) == '+')
			{
				operant_a = _stack.top();
				_stack.pop();
				operant_b = _stack.top();
				_stack.pop();
				operant_a += operant_b;
				if (operant_a > INT_MIN && operant_a < INT_MAX)
					_stack.push(operant_a);
				else
					throw std::range_error("Operation out of INT limits.");
			}
			else if (token.at(0) == '-')
			{
				operant_a = _stack.top();
				_stack.pop();
				operant_b = _stack.top();
				_stack.pop();
				operant_a = operant_b - operant_a;
				if (operant_a > INT_MIN && operant_a < INT_MAX)
					_stack.push(operant_a);
				else
					throw std::range_error("Operation out of INT limits.");
				_stack.push(operant_a);
			}
			else if (token.at(0) == '*')
			{
				operant_a = _stack.top();
				_stack.pop();
				operant_b = _stack.top();
				_stack.pop();
				operant_a *= operant_b;
				if (operant_a > INT_MIN && operant_a < INT_MAX)
					_stack.push(operant_a);
				else
					throw std::range_error("Operation out of INT limits.");
				_stack.push(operant_a);
			}
			else if (token.at(0) == '/') 
			{
				operant_a = _stack.top();
				_stack.pop();
				operant_b = _stack.top();
				_stack.pop();
				if (operant_a != 0)
					operant_a = operant_b / operant_a;
				else
					throw std::runtime_error("Division by zero.");
				_stack.push(operant_a);
			}
		}
	}
	while (!_stack.empty())
	{
		std::cout << _stack.top() << std::endl;
		_stack.pop();
	}
}

bool	ft_isDigit(char c)
{
    if (c >= 48 && c <= 57)
		return true;
	return false;
}

bool	ft_isSpace(char c)
{
	if (c == 32)
		return true;
	return false;
}

bool	ft_isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}
