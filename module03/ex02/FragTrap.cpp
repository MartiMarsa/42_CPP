/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:48:54 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/07 15:48:57 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor has been called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
    	this->_hitPoints = other._hitPoints;
    	this->_attackDamage = other._attackDamage;
    	this->_energyPoints = other._energyPoints;
    	this->_name = other._name;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor has been called." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() && this->getHitPoints())
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "FragTrap " << this->getName() << " attacks " << target;
		std::cout << ", causing " << this->getAttackDamage() << " points of damage!";
		std::cout << " AaaAAAAAAAAAAAaaAAAaaaaAAAAAAAhhhhhh!!!!!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->getName() << " can't do this action right now.";
		std::cout << std::endl;
	}
}
void	FragTrap::highFivesGuys(void)
{
	std::cout << "Wow, such skill, much impress. High FIVE, champion. " << std::endl;
}
