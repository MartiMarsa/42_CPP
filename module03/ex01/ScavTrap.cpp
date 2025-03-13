/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:51:49 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/06 18:51:50 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->setName("Felipe III");
	this->sethitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap default construtor has been called." << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->sethitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap constructor, which gathers the name from parameter,";
	std::cout << " has been called." << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor has been called." << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return (*this);
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor has been called." << std::endl;
}
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode.";
	std::cout << "You don't want to mess with it." << std::endl;
}
void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() && this->getHitPoints())
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "ScavTrap " << this->getName() << " attacks " << target;
		std::cout << ", causing " << this->getAttackDamage() << " points of damage!";
		std::cout << " That's even more incredible! WOo000ooOO00oooowwwWW!!!!!!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() << " can't do this action right now.";
		std::cout << std::endl;
	}
}