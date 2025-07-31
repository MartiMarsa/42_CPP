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

int main(int argc, char **argv)
{
	BitcoinExchange	btc;

	try
	{	
		if (argc != 2 || !btc.isValidFile(argv[1]))
		{
			std::cerr << "Error: This program takes a database .txt storing prices/dates ";
			std::cerr << "to evaluate. Please provide the correct file. Be sure it ";
			std::cerr << "exists and has the correct persmissions." << std::endl;
			return 1;
		}
		btc.loadCsvToMap("data.csv");
		btc.btcExchange(argv[1]);
		// btc.printDataBase();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caugth an exception: " << e.what() << '\n';
	}

	return 0;
}
