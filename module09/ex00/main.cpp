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
		std::cerr << "exists and has the correct persmisions." << std::endl;
		return 1;
	}
	std::cout << "ok" << std::endl;
	return 0;
}
