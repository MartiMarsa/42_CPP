/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:25:23 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/05 19:25:25 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ClapTrap	cT1(argv[1]);
		cT1.attack("the enemy");
		cT1.beRepaired(100);
		std::cout << "ClapTrap " << cT1.getName() << " has " << cT1.getHitPoints();
		std::cout << " hit points and "<< cT1.getEnergyPoints() << " energy points.";
		std::cout << std::endl;
	}
	else
		std::cout << "Choose a robot name" << std::endl;
	return (0);
}