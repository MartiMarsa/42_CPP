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

static bool	isSpecial(std::string &data)
{
	if (data == "-inff" || data == "inff" || data == "-inf" || data == "inf"
		|| data == "nanf" || data == "nan")
		return (1);
	return (0);
}

static bool	isChar(std::string &data, size_t &len)
{
	if (len == 1 && !isdigit(data[0]))
		return (1);
	if (len == 3 && data[0] == '\'' && data[2] == '\'')
		return (1);
	return (0);
}

static bool isInt(std::string &data, size_t &len)
{
	size_t i = 0;

	if (data[0] == '-' || data[0] == '+')
	{
		if (len == 1)
			return 0;
		++i;
	}
	for (; i < len; ++i)
		if (isdigit(data[i]))
			return (1);
	return (0);
}

dataType	whichType(std::string &data, size_t &len)
{
    size_t	dot = data.find('.');
    size_t	f = data.find('f');
	
	if (dot == std::string::npos && f == std::string::npos)
	{
		if (isSpecial(data))
			return SPECIAL;
		if (isChar(data, len))
			return CHAR;
		if (isInt(data, len))
			return INT;
	}
}
