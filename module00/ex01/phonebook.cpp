/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:17:19 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/19 16:17:22 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	_index = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::addContact()
{
	_contactlist[_index % 8].setNew();
	_index++;
}

void	PhoneBook::searchContact() const
{
	std::string input;
	bool		check = false;
	int			i;

	displayContact();
	while (!check)
	{
		std::cout << "Choose the contact (Index) you want to see." << std::endl;
		if (!getline(std::cin, input))
		{
			std::cout << "sayonara baby." << std::endl;
			exit (1);
		}
		if (input.empty())
			continue;
		else if (input == "EXIT")
		{
			std::cout << "Hasta luego MariCarmen." << std::endl;
			exit (1);
		}
		else if (isdigit(input[0]) && input.length() == 1 && input[0] > '0' && input[0] <= '8')
			check = true;
		else
			std::cout << "Error: enter a valid index." << std::endl;
	}
	i = input[0] - 48;
	if (i <= _index)
	{
		std::cout << _contactlist[--i].getFirstName() << std::endl;
		std::cout << _contactlist[i].getLastName() << std::endl;
		std::cout << _contactlist[i].getNickName() << std::endl;
		std::cout << _contactlist[i].getPhoneNumber() << std::endl;
		std::cout << _contactlist[i].getDarkestSecret() << std::endl;
		std::cout << "Thanks for using the service. Do you need something else?" << std::endl;
	}
	else
		std::cout << "The index is not valid." << std::endl;
}

void	PhoneBook::displayContact() const
{
	std::cout << std::endl << std::setw(10) << " Index   " << "|";
    std::cout << std::setw(10) << "First Name" << "|" << std::setw(10);
    std::cout << "Last Name " "|"<< std::setw(10) << "Nick Name " << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	for (int i = 0; i < 8 && i < _index; i++)
	{
		std::cout << std::setw(5) << i + 1 << "     |";
		if (_contactlist[i].getFirstName().size() > 10)
			std::cout << std::setw(9) << _contactlist[i].getFirstName().substr(0,9) << ".|" ;
		else
			std::cout << std::setw(10) << _contactlist[i].getFirstName() << "|";
		if (_contactlist[i].getLastName().size() > 10)
			std::cout << std::setw(9) << _contactlist[i].getLastName().substr(0,9) << ".|";
		else
			std::cout << std::setw(10) << _contactlist[i].getLastName() << "|";
		if (_contactlist[i].getNickName().size() > 10)
			std::cout << std::setw(9) << _contactlist[i].getNickName().substr(0,9) << ".|";
		else
			std::cout << std::setw(10) << _contactlist[i].getNickName();
		std::cout << std::endl;
	}
}