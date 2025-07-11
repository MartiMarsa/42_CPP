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

	// missing validations
	
}
bool	loadCsvToMap(const std::string &file, std::map<std::string, float> &btcDataBase)
{
	std::ifstream	dB(file.c_str());
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
	}
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
	
	std::cout << "ok" << std::endl;
	return 0;
}
