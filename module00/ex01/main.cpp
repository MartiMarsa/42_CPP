/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:55:35 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/19 14:55:37 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	rolodex;
	
	std::cout << "Hello! This is the worst phonebook ever seen! Use ADD, SEARCH or EXIT to enjoy it." << std::endl;
	while (42)
	{
		if (!getline(std::cin, input))
		{
			std::cout << "ciao pringao." << std::endl;
			return (1);
		}
		if (input.empty())
			std::cout << "????? " << std::endl;
		else if (input == "ADD")
			rolodex.addContact();
		else if (input == "SEARCH")
			rolodex.searchContact();
		else if (input == "EXIT")
		{
			std::cout << "Ciaoooooooooo" << std::endl;
			return (0);
		}
		else
			std::cout << "The program only accepts ADD, SEARCH and EXIT." << std::endl;
	}
	return (0);
}