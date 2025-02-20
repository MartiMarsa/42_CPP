/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:26:37 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/19 11:26:39 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

void    Contact::setNew()
{
    _firstName = Contact::_readInput("First name: ");
    _lastName = Contact::_readInput("Last name: ");
    _nickName = Contact::_readInput("Nick name: ");
    _phoneNumber = Contact::_readPhone("Telephone number: ");
    _darkestSecret = Contact::_readInput("Darkest secret: ");
	std::cout << "Contact data saved. Ready for new orders." << std::endl;
}

std::string Contact::getFirstName() const
{
    return (_firstName); 
}

std::string Contact::getLastName() const
{
    return (_lastName);
}

std::string Contact::getNickName() const
{
    return (_nickName);
}

std::string Contact::getPhoneNumber() const
{
    return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return (_darkestSecret);
}

std::string Contact::_readInput(std::string message) const
{
    std::string input;
    bool    check = false;

	while (!check)
	{
		std::cout << message << std::endl;
		if (!getline(std::cin, input))
		{
			std::cout << "ciao pringao." << std::endl;
			exit (1);
		}
		if (input.empty())
			std::cout << "Enter some data, please." << std::endl;
		else if (input == "EXIT")
		{
			std::cout << "Hasta luego MariCarmen." << std::endl;
			exit (1);
		}
		else
			check = true;
	}
	return (input);
}

std::string Contact::_readPhone(std::string message) const
{
	std::string	input;
	bool	check = false;

	while (!check)
	{
		std::cout << message << std::endl;
		if (!getline(std::cin, input))
		{
			std::cout << "venga, hasta luego." << std::endl;
			exit (1);
		}
		if (input.empty())
			std::cout << "Enter some data, please." << std::endl;
		else if (input == "EXIT")
		{
			std::cout << "Hasta luego MariCarmen." << std::endl;
			exit (1);
		}
		else if (!_checkDigits(input))
			std::cout << "A telephone number should contain only digits." << std::endl;
		else
			check = true;
	}
	return (input);
}

bool		Contact::_checkDigits(const std::string &str)  const
{
	if (str.empty())
		return false;
	for (unsigned long i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}