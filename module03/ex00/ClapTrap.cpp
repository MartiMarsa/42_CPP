/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:25:53 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/05 19:25:55 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Juan Carlos"), _hitPoints(10),
_energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor has been called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
_energyPoints(10), _attackDamage(0)
{
	std::cout << "The constructor which gathers the name atribute from parameter";
	std::cout << " has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
_attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor has been called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_attackDamage = other._attackDamage;
        this->_energyPoints = other._energyPoints;
        this->_hitPoints = other._energyPoints;
    }
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor has been called." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() && this->getHitPoints())
	{
		this->setEnergyPoints(-1);
		std::cout << "ClapTrap " << this->getName() << " attacks " << target;
		std::cout << ", causing " << this->getAttackDamage() << " points of damage!";
		std::cout << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getEnergyPoints() && this->getHitPoints())
	{
		this->sethitPoints(-amount);
		std::cout << "ClapTrap " << this->getName() << " recieved " << amount;
		std::cout << " points of damage!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() && this->getHitPoints())
	{
		this->setEnergyPoints(-1);
		this->sethitPoints(amount);
		std::cout << "ClapTrap " << this->getName() << " repairs " << amount;
		std::cout <<" hit points!" << std::endl;
	}
}
std::string	ClapTrap::getName()
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints()
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints()
{
	return(_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage()
{
	return (_attackDamage);
}

void	ClapTrap::setEnergyPoints(int amount)
{
	this->_energyPoints += amount;
}

void	ClapTrap::sethitPoints(int amount)
{
	this->_hitPoints += amount;
}

