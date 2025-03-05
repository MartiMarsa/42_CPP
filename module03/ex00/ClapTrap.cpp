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

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor has been called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
_energyPoints(10), _attackDamage(10)
{
	std::cout << "The constructor which gathers the name atribute has been";
	std::cout << "called." << std::endl;
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
	if (this->_energyPoints && this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!";
		std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints && this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " recieved " << amount;
		std::cout << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints && this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " repairs " << amount;
		std::cout <<" hit points!" << std::endl;
}