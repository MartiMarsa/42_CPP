/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:47:15 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/07 19:47:17 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor has been called." << std::endl;
    DiamondTrap::_name = "Shiny-robot";
    ClapTrap::setName("Shiny-robot_clap_name");
    this->sethitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(30);
}
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
    std::cout << "DiamondTrap constructor, that gathers the name from parameters";
	std::cout << " has been called." << std::endl;
    ClapTrap::setName(name.append("_clap_name"));
    this->sethitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy-constructor has been called." << std::endl;
	DiamondTrap::_name = other._name;
	ClapTrap::setName(DiamondTrap::_name.append("_clap_name"));
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	this->_hitPoints = other._hitPoints;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		DiamondTrap::_name = other._name;
		ClapTrap::setName(DiamondTrap::_name.append("_clap_name"));
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return (*this);
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor has been called." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target); 
}
void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is " << _name << " but my ClapTrap ";
	std::cout <<  "name is " << ClapTrap::getName() << std::endl;
}
