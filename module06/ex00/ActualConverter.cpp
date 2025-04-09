/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ActualConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:05:01 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/08 19:05:04 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    printSpecial(const std::string &data)
{
    if (data == "nan" || data == "nanf")
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
    if (data == "-inf" || data == "-inff")
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
    if (data == "+inf" || data == "+inff")
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
}

void		toChar(std::string &data, dataType type, double db)
{
	std::cout << "char: ";
	if (type == CHAR)
		std::cout << "'" << data << "'" << std::endl;
	else
	{
		int		n = static_cast<int>(roundf(db));
		if (n > 32 && n < 127)
			std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
		else if (n >= CHAR_MIN && n <= UCHAR_MAX)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void		toInt(dataType type, double db)
{
	std::cout << "int: ";
	if (type == CHAR)
		std::cout << static_cast<int>(roundf(db)) << std::endl;
	else if (db <= INT_MAX && db >= INT_MIN)
		std::cout << static_cast<int>(roundf(db)) << std::endl;
	else
		std::cout << "impossible: " << (db < 0 ? "underflow" : "overflow") << std::endl;
}

void		toFloat(std::string &data, dataType type, double db, size_t len)
{
	std::cout << "float: ";
	if (type == FLOAT || type == DOUBLE)
	{
		size_t	dot = data.find('.');
		size_t	f = data.find('f');
		std::cout << std::fixed << std::setprecision((f == std::string::npos ? len - ++dot
												: f - ++dot)) << db << "f" << std::endl;
	}
	else if(type == CHAR || type == INT)
		std::cout << db << ".0f" << std::endl;
}

void		toDouble(std::string &data, dataType type, double db, size_t len)
{

	std::cout << "double: ";
	if (type == FLOAT || type == DOUBLE)
	{
		size_t	dot = data.find('.');
		size_t	f = data.find('f');
		std::cout << std::fixed << std::setprecision((f == std::string::npos ? len - ++dot
												: f - ++dot)) << db << std::endl;
	}
	else if(type == CHAR || type == INT)
		std::cout << db << ".0" << std::endl;
}

double	cast(std::string & value, size_t &len)
{
	if (len == 1)
		return static_cast<double>(value[0]);
	else if (len == 3 && value[0] == '\'' && value[2] == '\'')
		return static_cast<double>(value[1]);
	std::stringstream ss(value);
    double d;
   	ss >> d;
	return d; 
}