/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:34:26 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/10 17:34:29 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <map>
# include <algorithm>
# include <ctype.h>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_btcDB;

		int		stringToInt(const std::string &str);
		float	strToFloat(const std::string &str);
		float	parseAmount(const std::string &amount, const std::string &str);
		bool    isValidRateFormat(const std::string &str, bool &isFloat);
		bool	isValidDateFormat(const std::string &date);
		bool	isFileTxt(const std::string &filename);
		bool	canBeOpened(const std::string &filename);
		float	multiplyOperands(const std::string & date, float op);
		void	printResults(const std::string &date, float amount, float result) const;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		bool	loadCsvToMap(const std::string &file);
		bool	isValidFile(const std::string &filename);
		void	btcExchange(const std::string &input);
		void	printDataBase() const;
		const std::map<std::string, float> &	getBtcDataBase() const;
};

#endif