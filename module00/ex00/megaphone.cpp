/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:32:22 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/18 13:32:31 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

std::string	myToUpper(std::string str)
{
	for (unsigned long i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i]);
	return (str);
}

void	printStr(std::string str)
{
	std::cout << str << std::endl;
}

int	main	(int argc, char **argv)
{
	if (argc == 1)
	{
		printStr("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		return (0);
	}
	for (int i = 1; i < argc; ++i)
		std::cout << myToUpper(argv[i]) << " ";
	std::cout << std::endl;
	return (0);
}
