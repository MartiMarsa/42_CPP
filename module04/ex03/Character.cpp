/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:47:17 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/17 16:47:19 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Someone")
{
    for (int i = 0; i < BAG; ++i)
        this->_slot[i] = NULL;
    _floorCapacity = 4;
    _floorIdx = 0;
    _floor = new AMateria*[_floorCapacity];
    for (unsigned int i = 0; i < _floorCapacity; ++i)
        _floor[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{    
	for (int i = 0; i < BAG; ++i)
		this->_slot[i] = NULL;
    _floorCapacity = 4;
    _floorIdx = 0;
    _floor = new AMateria*[_floorCapacity];
    for (unsigned int i = 0; i < _floorCapacity; ++i)
        _floor[i] = NULL;
}

Character::Character(const Character &other)
{
	this->_name = other._name;
	for (int i = 0; i < BAG; ++i)
	{
		if (other._slot[i] == NULL)
			this->_slot[i] = NULL;
		else
			this->_slot[i] = other._slot[i]->clone();
	}
    this->_floorCapacity = other.getFloorCapacity();
    this->_floorIdx = other.getFloorIdx();
    this->_floor = new AMateria*[_floorCapacity];
    for (unsigned int i = 0; i < this->_floorCapacity; ++i)
    {
        if (other._floor[i] == NULL)
            this->_floor[i] = NULL;
        else
            this->_floor[i] = other._floor[i]->clone();
    }
}

Character   &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < BAG; ++i)
        {
            if (this->_slot[i] != NULL)
            {
                delete this->_slot[i];
                this->_slot[i] = NULL;
            }
            if (other._slot[i] != NULL)
                this->_slot[i] = other._slot[i]->clone();
        }
		this->clearFloor();
		if (this->_floor)
        	delete _floor;
        this->_floorCapacity = other.getFloorCapacity();
        this->_floorIdx = other.getFloorIdx();
        _floor = new AMateria*[_floorCapacity];
        for (unsigned int i = 0; i < this->_floorCapacity; ++i)
        {
            if (other._floor[i] == NULL)
                this->_floor[i] = NULL;
            else
                this->_floor[i] = other._floor[i]->clone();
        }
    }
}

Character::~Character()
{
	for (int i = 0; i < BAG; ++i)
	{
		if (this->_slot[i] != NULL)
		{
			delete this->_slot[i];
			this->_slot[i] = NULL;
		}
	}
	this->clearFloor();
	if (this->_floor)
	{
		delete[] this->_floor;
		this->_floor = NULL;
	}
}

std::string const   &Character::getName() const
{
    return (_name);
}

void    Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "Character " << this->getName() << " wasn't able to equip";
		std::cout << " that." << std::endl;
		return;
	}
	for (int i = 0; i < BAG; ++i)
	{
		if (this->_slot[i] == m)
			return;
	}
	for (int i = 0; i < BAG; ++i)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			std::cout << "Character " << this->getName() << " was equiped with ";
			std::cout << m->getType() << " succesfully." << std::endl;
			return ;
		}
	}
	std::cout << "Seems character " << this->getName() << " inventory' is full.";
	std::cout << std::endl;
	this->addToFloor(*m);
}

void    Character::unequip(int idx)
{
	if (idx < 0 || idx >= BAG)
	{
		std::cout << "Unequip error: use a valid index between 0 and 3." << std::endl;
		return;
	}
	if (this->_slot[idx] == NULL)
	{
		std::cout << "Unequip error: character " << this->getName();
		std::cout << " has nothing equiped." << std::endl;
	}
	std::cout << "Character " << this->getName() << " unequiped n* " << idx;
	std::cout << " of their inventory." << std::endl;
	this->addToFloor(*this->_slot[idx]);
	this->_slot[idx] = NULL;
}

void    Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= BAG)
	{
		std::cout << "Use error: use a valid index between 0 and 3." << std::endl;
		return;
	}
	if (this->_slot[idx] == NULL)
	{
		std::cout << "Use error: character " << this->getName();
		std::cout << " has nothing equiped." << std::endl;
	}
	std::cout << "Character " << this->getName();
}

void    Character::clearFloor()
{
	for (unsigned int i = 0; i < this->_floorCapacity; ++i)
    {
        if (this->_floor[i] != NULL)
        {
            delete this->_floor[i];
            this->_floor[i] = NULL;
        }
    }
	this->_floorIdx = 0;
}