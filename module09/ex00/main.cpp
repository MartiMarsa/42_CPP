/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:33:53 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/10 17:33:55 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	stringToInt(const std::string &str)
{
	std::istringstream iss(str);
	int result;
	iss >> result;
	if (iss.fail())
		throw std::runtime_error("Convertion failed.");
	return result;
}

float	strToFloat(const std::string &str)
{
	std::istringstream	iss(str);
	float	result;
	iss >> result;
	if (iss.fail())
		throw std::runtime_error("Error in conversion.");
	return result;
}

bool    isValidRateFormat(const std::string &str, bool &isFloat)
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

bool	isValidDateFormat(const std::string &date)
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
bool	loadCsvToMap(const std::string &file, std::map<std::string, float> &btcDataBase)
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
			std::cerr << "Error: Invalid line. Bad date format." << std::endl;
			continue; 
		}
		if (!std::getline(ss, rateStr) || !isValidRateFormat(rateStr, isFloat))
		{
			std::cerr << "Error: Invalid line. Bad Rate format." << std::endl;
			continue;
		}
		std::pair<std::string, float> dateRate = std::make_pair(date, strToFloat(rateStr));
		// std::cout << "Date -> " << dateRate.first << " Rate -> " << dateRate.second << std::endl;
		btcDataBase.insert(dateRate);
	}
	return true;
}

bool	isFileTxt(const std::string &filename)
{
	if (filename.length() >= 4)
		return (filename.substr(filename.length() - 4) == ".txt");
	return false;
}

bool	canBeOpened(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	return file.is_open();
}

bool	isValidFile(const std::string &filename)
{
	return (isFileTxt(filename) && canBeOpened(filename));
}

int main(int argc, char **argv)
{
	if (argc != 2 || !isValidFile(argv[1]))
	{
		std::cerr << "Error: This program takes a database .txt storing prices/dates ";
		std::cerr << "to evaluate. Please provide the correct file. Be sure it ";
		std::cerr << "exists and has the correct persmissions." << std::endl;
		return 1;
	}
	std::map<std::string, float>	btcDataBase;

	loadCsvToMap("data.csv", btcDataBase);
	std::map<std::string, float>::const_iterator	it = btcDataBase.begin();
	for (; it != btcDataBase.end(); ++it)
	{
		std::cout << "Date -> " << it->first << " Rate -> " << it->second << std::endl;
	}
	return 0;
}
