/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:01:31 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/05 16:01:32 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp" 

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {}

Point   &Point::operator=(const Point &other)
{
    if (this != &other)
    {
		std::cout << "Error: operand types are: const Fixed = const Fixed" << std::endl;
    }
    return (*this);
}

Point::~Point() {}

const Fixed Point::getX() const
{
	return (this->_x);
}

const Fixed Point::getY() const
{
	return (this->_y);
}