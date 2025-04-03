/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:09:02 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/03 13:09:04 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

void    ScalarConverter::convert(std::string & value)
{
    size_t      len = value.length();
    dataType    type = whichType(value, len);

	switch (type)
	{
		case SPECIAL:
			printSpecial(value);
			break;
		case CHAR:
			toChar(value, len);
			break;
		case INT:
			toInt(value);
			break;
		case FLOAT:
			toFloat(value);
			break;
		case DOUBLE:
			toDouble(value);
			break;
	}
}

const char*  badInput::what() const throw()
{
	return "wrong input my friend."
}
