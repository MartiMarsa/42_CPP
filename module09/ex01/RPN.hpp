/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:20:50 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/17 19:20:52 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
private:
    std::stack<long long int> _stack;
public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	bool	isAllowedCharacter(const std::string & input);
    bool	validateInput(const std::string & input);
    void    reversePolishNotation(const std::string & input);
};

bool	ft_isDigit(char c);
bool	ft_isSpace(char c);
bool	ft_isOperator(char c);

#endif