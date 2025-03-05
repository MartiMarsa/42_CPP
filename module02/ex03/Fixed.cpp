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


Fixed::Fixed(): _value(0) {}

Fixed::Fixed( const Fixed &other ) : _value(other._value) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int intnbr) : _value(intnbr << _fractBits) {}

Fixed::Fixed(const float floatnbr) : _value(roundf(floatnbr * (1 << _fractBits))) {}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed Fixed::operator+(const Fixed &other)
{
    return Fixed((this->toFloat() + other.toFloat()));
}
Fixed Fixed::operator-(const Fixed &other)
{
    return Fixed((this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other)
{
    return Fixed((this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	if (other._value == 0)
	{
		std::cout << "Don't do that brrr." << std::endl;
		return (*this);
	}
    return Fixed((this->toFloat() / other.toFloat()));
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

bool Fixed::operator<(const Fixed &other) const {return _value < other.getRawBits();}

bool Fixed::operator>(const Fixed &other) const {return _value > other.getRawBits();}

bool Fixed::operator==(const Fixed &other) const{return _value == other.getRawBits();}

bool Fixed::operator!=(const Fixed &other) const{return _value != other.getRawBits();}

bool Fixed::operator<=(const Fixed &other) const{return _value <= other.getRawBits();}

bool Fixed::operator>=(const Fixed &other) const{return _value >= other.getRawBits();}

Fixed	&Fixed::operator++()
{
	++_value;
	return (*this);	
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++_value;
	return (temp);	
}

Fixed	&Fixed::operator--()
{
	--_value;
	return (*this);	
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--_value;
	return (temp);	
}

Fixed&	Fixed::min(Fixed &one, Fixed &two)
{
	if (one < two)
		return (one);
	else
		return (two);
}

const Fixed&	Fixed::min(const Fixed &one, const Fixed &two)
{
	if (one < two)
		return (one);
	else
		return (two);
}

Fixed&	Fixed::max(Fixed &one, Fixed &two)
{
	if (one > two)
		return (one);
	else
		return (two);
}

const Fixed&	Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one > two)
		return (one);
	else
		return (two);
}