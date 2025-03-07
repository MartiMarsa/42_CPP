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

ClapTrap::ClapTrap() : _name("Mauricio Colmenero"), _hitPoints(10),
_energyPoints(10), _attackDamage(0)
{
	std::cout << RED << "ClapTrap default constructor has been called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor, which gathers the name atribute from parameter,";
	std::cout << " has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor has been called." << std::endl;
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
	std::cout << "ClapTrap destructor has been called." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() && this->getHitPoints())
	{
		this->setEnergyPoints( this->getEnergyPoints() -1);
		std::cout << "ClapTrap " << this->getName() << " attacks " << target;
		std::cout << ", causing " << this->getAttackDamage() << " points of damage!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->getName() << " can't do this action right now.";
		std::cout << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() >= amount)
	{
		this->sethitPoints(this->getHitPoints() - amount);
		std::cout << "ClapTrap " << this->getName() << " recieved " << amount;
		std::cout << " points of damage!" << std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << this->getName() << " recieved " << amount;
		std::cout << " points of damage! It's practically dead! :(" << std::endl;

	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() && this->getHitPoints())
	{
		this->setEnergyPoints(this->getEnergyPoints() -1);
		this->sethitPoints(amount + this->getHitPoints());
		std::cout << "ClapTrap " << this->getName() << " repairs " << amount;
		std::cout <<" hit points!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->getName() << " can't do this action right now.";
		std::cout << std::endl;
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

void	ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void	ClapTrap::sethitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}
void	ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}
