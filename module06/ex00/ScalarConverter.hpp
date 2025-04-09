/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:08:49 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/03 13:08:50 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCOVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cmath>
# include <climits>
# include <sstream>
#include <iomanip>

enum	dataType
{
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	BADTYPE
};

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
	public:
		static void		convert(std::string & value);
};

class badInput : public std::exception
{
	public:
		const char* what() const throw();
};

dataType	whichType(const std::string &data, const size_t &len);

void		printSpecial(const std::string &data);
void		toChar(std::string &data, dataType type, double db);
void		toInt(dataType type, double db);
void		toFloat(std::string &data, dataType type, double db, size_t len);
void		toDouble(std::string &data, dataType type, double db, size_t len);
double		cast(std::string & data, size_t &len);

#endif
