/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:21:04 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/28 09:21:05 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void    Harl::complain(std::string level)
{
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*funcArray[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = -1; i < 4; ++i)
	{
		if (level == levels[i])
		{
			(this->*funcArray[i])();
			return ;
		}
	}
	std::cout << "Please, insert a valid command." << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "[DEBUG] - Why does my burger look like it was assembled by"; 
	std::cout << " someone playing Jenga?" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO] - You say the WiFi is free, but I’m paying with ";
	std::cout << "my patience waiting for a single page to load." << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING] - I don’t mean to sound dramatic, but this is ";
	std::cout << "the third time I’ve been here, and you still put pickles ";
	std::cout << "in my ‘no pickles’ burger." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR] - I demand to speak to the manager. I ordered food, ";
	std::cout << "not a scavenger hunt. Why am I missing half my order?" << std::endl;
}

