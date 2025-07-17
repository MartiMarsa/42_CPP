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