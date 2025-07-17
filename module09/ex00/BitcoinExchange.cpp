/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:10:26 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/17 12:10:27 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	BitcoinExchange::stringToInt(const std::string &str)
{
	std::istringstream iss(str);
	int result;
	iss >> result;
	if (iss.fail())
		throw std::runtime_error("Convertion failed.");
	return result;
}

float	BitcoinExchange::strToFloat(const std::string &str)
{
	std::istringstream	iss(str);
	float	result;
	iss >> result;
	if (iss.fail())
		throw std::runtime_error("Error in conversion.");
	return result;
}

bool    BitcoinExchange::isValidRateFormat(const std::string &str, bool &isFloat)
{
    size_t dot = str.find('.');
	float	rateStr;
    if (dot != std::string::npos)
	{
        isFloat = true;
    	for (size_t i = 0; i != dot; ++i)
    	{
    	    if (!isdigit(str.at(i)))
    	        return false;
    	}
    	for (size_t i = ++dot; i != str.size(); ++i)
    	{
    	    if (!isdigit(str.at(i)))
    	        return false;
    	}
		try {
			rateStr = strToFloat(str);
		}
		catch(const std::exception &e) {
			std::cerr << "Caught an exception: " << e.what() << std::endl;
		}
		if (rateStr < 0)
			return false;
	}
	else {
		for (size_t i = 0; i != str.size(); ++i)
		{
			if (!isdigit(str.at(i)))
				return false;
		}
		try {
			rateStr = strToFloat(str);
		}
		catch(const std::exception &e) {
			std::cerr << "Caught an exception: " << e.what() << std::endl;
		}
		if (rateStr < 0)
			return false;
	}
    return true;
}

bool	BitcoinExchange::isValidDateFormat(const std::string &date)
{
	if (date.length() != 10)
		return false;
	if (date.at(4) != '-' || date.at(7) != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date.at(i)))
			return false;
	}
	int year, month, day;
	try {
	year = stringToInt(date.substr(0, 4));
	month = stringToInt(date.substr(5, 2));
	day = stringToInt(date.substr(8, 2));
	if (year > 9999 || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	}
	catch(std::exception &e) {
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
	return true;
}


float	BitcoinExchange::parseAmount(const std::string &amount, const std::string &str)
{
	if (amount.at(0) == '-')
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return -1;		
	}
	size_t dot = amount.find('.');
	float	op = 0;
    if (dot != std::string::npos)
	{
    	for (size_t i = 0; i != dot; ++i)
    	{
    	    if (!isdigit(amount.at(i)))
			{
				std::cerr << "Error: bad input => " << str << std::endl;
				return -1;
			}
    	}
    	for (size_t i = ++dot; i != amount.size(); ++i)
    	{
    	    if (!isdigit(amount.at(i)))
			{
				std::cerr << "Error: bad input => " << str << std::endl;
				return -1;
			}
    	}
		try {
			op = strToFloat(amount);
		}
		catch(const std::exception &e) {
			std::cerr << "Caught an exception: " << e.what() << std::endl;
		}
		if (op > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			return -1;
		}
	}
	else {
		for (size_t i = 0; i != amount.size(); ++i)
		{
			if (!isdigit(amount.at(i)))
			{
				std::cerr << "Error: bad input => " << str << std::endl;
				return -1;
			}
		}
		try {
			op = strToFloat(amount);
		}
		catch(const std::exception &e) {
			std::cerr << "Caught an exception: " << e.what() << std::endl;
		}
		if (op > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			return -1;
		}
	}
    return op;
}

float	BitcoinExchange::multiplyOperands(const std::string & date, float op)
{
	std::map<std::string, float>::iterator it = _btcDB.begin();

	for (; it != _btcDB.end() && it->first <= date; ++it)
	{
		if (it->first == date)
			return it->second * op;
	}
	if (it == _btcDB.end())
	{
		--it;
		return it->second * op;
	}
	if (it->first > date)
	{
		--it;
		return it->second * op;
	}
	return -1;
}

void	BitcoinExchange::printResults(const std::string &date, float amount, float result) const
{
	std::cout << date << " => " << amount << " = " << (date < "2010-08-20" ? 0 : result) << std::endl;
}

void    BitcoinExchange::btcExchange(const std::string &input)
{
    std::ifstream   in(input.c_str());
    std::string		str;
	bool			firstLine = true;

	while(std::getline(in, str))
	{
		if (firstLine)
		{
			firstLine = false;
			continue;
		}
		std::string line(str);
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		std::stringstream 	ss(line);
		std::string			date;
		std::string			amount;

		if (!std::getline(ss, date, '|') || !isValidDateFormat(date))
		{
			std::cerr << "Error: bad input => " << str << std::endl;
			continue;
		}
		if (!std::getline(ss, amount))
		{
			std::cerr << "Error: missing or malformed amount field." << std::endl;
			continue;
		}
		float	op = parseAmount(amount, str);
		if (op == -1)
			continue;
		float	result = multiplyOperands(date, op);
		if (result == -1)
			continue;
		printResults(date, op, result);
	}
}

bool	BitcoinExchange::loadCsvToMap(const std::string &file)
{
	std::ifstream	dB(file.c_str());
	bool	flag = false;
	bool	&isFloat = flag;
	if (!dB.is_open())
	{
		std::cerr << "Error: This program needs \"data.csv\" in the same executable's ";
		std::cerr << "directory. Be sure it exists and has the correct permissions." << std::endl;
		return false;
	}
	std::string	line;
	bool		firstLine = true;

	while(std::getline(dB, line))
	{
		if(firstLine)
		{
			firstLine = false;
			continue;
		}

		std::stringstream ss(line);
		std::string date;
		std::string rateStr;

		if (!std::getline(ss, date, ',') || !isValidDateFormat(date))
		{
			// std::cerr << "Error: Invalid line. Bad date format." << std::endl;
			continue; 
		}
		if (!std::getline(ss, rateStr) || !isValidRateFormat(rateStr, isFloat))
		{
			// std::cerr << "Error: Invalid line. Bad Rate format." << std::endl;
			continue;
		}
		std::pair<std::string, float> dateRate = std::make_pair(date, strToFloat(rateStr));
		// std::cout << "Date -> " << dateRate.first << " Rate -> " << dateRate.second << std::endl;
		this->_btcDB.insert(dateRate);
	}
	return true;
}

bool	BitcoinExchange::isFileTxt(const std::string &filename)
{
	if (filename.length() >= 4)
		return (filename.substr(filename.length() - 4) == ".txt");
	return false;
}

bool	BitcoinExchange::canBeOpened(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	return file.is_open();
}

bool	BitcoinExchange::isValidFile(const std::string &filename)
{
	return (isFileTxt(filename) && canBeOpened(filename));
}


const std::map<std::string, float> &	BitcoinExchange::getBtcDataBase() const
{
	return _btcDB;
}

void	BitcoinExchange::printDataBase() const
{
	std::map<std::string, float>::const_iterator	it = _btcDB.begin();
	for (; it != _btcDB.end(); ++it)
	{
		std::cout << "Date -> " << it->first << " Rate -> " << it->second << std::endl;
	}
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_btcDB = other._btcDB;
	return *this;
}
