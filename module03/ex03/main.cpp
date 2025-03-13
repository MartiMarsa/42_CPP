/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:46:46 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/07 19:46:49 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << RED;
	ClapTrap		C("Son Goku");
	std::cout << "His stats are:" << std::endl;
	std::cout <<"Attack: " << C.getAttackDamage() << std::endl << "Hit Points: ";
	std::cout << C.getHitPoints() << std::endl << "Energy points: ";
	std::cout << C.getEnergyPoints() << std::endl;
	std::cout << BLUE;
    DiamondTrap     D("Vegeta");
	std::cout << "His stats are:" << std::endl;
	std::cout <<"Attack: " << D.getAttackDamage() << std::endl << "Hit Points: ";
	std::cout << D.getHitPoints() << std::endl << "Energy points: ";
	std::cout << D.getEnergyPoints() << std::endl;
	std::cout << RED;
	C.attack(D.getName());
	std::cout << BLUE;
	D.attack(C.getName());
	std::cout << RESET << C.getName() << " is almost dead. Look, he took some";
	std::cout << " Senzu Beans. He has recovered his energy and has became ";
	std::cout << "Super Sayan. His news stats are: " << std::endl;
	C.setAttackDamage(100);
	C.setEnergyPoints(100);
	C.sethitPoints(100);
	std::cout << RED <<"Attack: " << C.getAttackDamage() << std::endl << "Hit Points: ";
	std::cout << C.getHitPoints() << std::endl << "Energy points: ";
	std::cout << C.getEnergyPoints() << std::endl;
	C.attack(D.getName());
	std::cout << RESET << "The punch was so hard! " << D.getName()  << " is a bit ";
	std::cout << "groggy, let's ask his name if he remembers it." << std:: endl;
	std::cout << BLUE;
	D.whoAmI();
	std::cout << RESET;
    return (0);
}
