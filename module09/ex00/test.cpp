/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:27:04 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/14 12:27:05 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include <iostream>

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
		if (rateStr < 0 || rateStr > 1000)
			return false;
	}
	else {
		for (int i = 0; i != str.size(); ++i)
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
		if (rateStr < 0 || rateStr > 1000)
			return false;
	}
    return true;
}

int main(int argc, char **argv)
{
	bool	flag = false;
    bool	&isFloat = flag;

	if (argc != 1)
	{
		if (isValidRateFormat(argv[1], isFloat))
			std::cout << "Is Valid and it is a " << (isFloat ? "float." : "int.") << std::endl;
		else
			std::cout << "Wrong format baby." << std::endl;
	}
	return 0;
}