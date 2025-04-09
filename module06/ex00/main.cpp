/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:25:08 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/08 19:25:12 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./scalar_converter <value>" << std::endl;
		return (1);
	}
	std::string data = argv[1];
	try
	{
		ScalarConverter::convert(data);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught an exception: "<< e.what() << '\n';
	}
	return (0);
}

