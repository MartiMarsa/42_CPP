/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhichType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:26:18 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/03 19:26:25 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	isSpecial(const std::string &data)
{
	if (data == "-inff" || data == "+inff" || data == "-inf" || data == "+inf"
		|| data == "nanf" || data == "nan")
		return (1);
	return (0);
}

static bool	isChar(const std::string &data, const size_t &len)
{
	if (len == 1 && !isdigit(data[0]))
		return (1);
	if (len == 3 && data[0] == '\'' && data[2] == '\'')
		return (1);
	return (0);
}

static bool isInt(const std::string &data, const size_t &len)
{
	size_t i = 0;

	if (data[0] == '-' || data[0] == '+')
	{
		if (len == 1)
			return 0;
		++i;
	}
	for (; i < len; ++i)
		if (!isdigit(data[i]))
			return 0;
	return 1;
}

static bool isFloat(const std::string &data, const size_t &len)
{
	size_t	i = 0;

	if (data[0] == '-' || data[0] == '+')
	{
		if (len == 1)
			return 0;
		++i;
	}
	for (; i < len; ++i)
	{
		if (isdigit(data[i]))
			continue;
		else
			break;
	}
	if (data[i] != '.')
		return (0);
	++i;
	if (!isdigit(data[i]))
		return 0;
	for (; i < len; ++i)
	{
		if (isdigit(data[i]))
			continue;
		else
			break;
	}
	if (data[i] == 'f' && ++i == len)
		return (1);
	return (0);
}

static bool isDouble(const std::string &data, const size_t &len)
{
	size_t	i = 0;

	if (data[0] == '-' || data[0] == '+')
	{
		if (len == 1)
			return 0;
		++i;
	}
	for (; i < len; ++i)
	{
		if (isdigit(data[i]))
			continue;
		else
			break;
	}
	if (data[i] != '.')
		return (0);
	++i;
	for (; i < len; ++i)
		if (!isdigit(data[i]))
			return 0;
	return (1);
}

dataType	whichType(const std::string &data, const size_t &len)
{
    size_t	dot = data.find('.');
    size_t	f = data.find('f');
	
	if (isSpecial(data))
		return SPECIAL;
	if (dot == std::string::npos)
	{
		if (isChar(data, len))
			return CHAR;
		if (isInt(data, len))
			return INT;
	}
	if (dot != std::string::npos && f != std::string::npos)
		if (isFloat(data, len))
			return FLOAT;
	if (dot != std::string::npos && f == std::string::npos)
		if (isDouble(data, len))
			return DOUBLE;
	return BADTYPE;
}
