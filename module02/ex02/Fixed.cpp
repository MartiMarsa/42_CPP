/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:32:16 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/01 10:32:18 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int    Fixed::_fractBits = 8;

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
}

Fixed::Fixed(const int intnbr) : _value(intnbr << _fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatnbr) : _value(roundf(floatnbr * (1 << _fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

int		Fixed::toInt( void ) const
{
	return (_value >> _fractBits);
}

float	Fixed::toFloat( void ) const
{
	return (_value / (float) (1 << _fractBits));
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits( int const raw)
{
	_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	return (out << value.toFloat());
}
