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
	int	i = -1;
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	while (++i < 4)
	{
		if (level == levels[i])
			break;
	}
	switch (i)
	{
		case 0:
		{
			debug();
			std::cout << std::endl;
			goto case1;
		}
		case 1: case1:
		{
			info();
			std::cout << std::endl;
			goto case2;
		}
		case 2: case2:
		{
			warning();
			std::cout << std::endl;
			goto case3;
		}
		case 3: case3:
		{
			error();
			std::cout << std::endl;
			break;
		}	
		default: std::cout << "I don't undertand that brrrr." << std::endl;	
	}
	
}

void	Harl::debug( void )
{
	std::cout << "[DEBUG] - Why does my burger look like it was assembled by"; 
	std::cout << " someone playing Jenga?" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO] - You say the WiFi is free, but I'm paying with ";
	std::cout << "my patience waiting for a single page to load." << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING] - I don't mean to sound dramatic, but this is ";
	std::cout << "the third time I've been here, and you still put pickles ";
	std::cout << "in my 'no pickles' burger." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR] - I demand to speak to the manager. I ordered food, ";
	std::cout << "not a scavenger hunt. Why am I missing half my order?" << std::endl;
}

