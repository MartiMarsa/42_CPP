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
    this->_floorIdx = 0;
    // this->_floor = new AMateria*[_floorCapacity];
    // for (unsigned int i = 0; i < this->_floorIdx; ++i)
    // {
    //     if (other._floor[i] == NULL)
    //         this->_floor[i] = NULL;
    //     else
    //         this->_floor[i] = other._floor[i]->clone();
    // }
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
		if (this->_floor != NULL)
        	delete[] this->_floor;
        this->_floorCapacity = other.getFloorCapacity();
        this->_floorIdx = other.getFloorIdx();
        _floor = new AMateria*[_floorCapacity];
        for (unsigned int i = 0; i < this->_floorIdx; ++i)
        {
            if (other._floor[i] == NULL)
                this->_floor[i] = NULL;
            else
                this->_floor[i] = other._floor[i]->clone();
        }
    }
	return (*this);
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
	std::cout << "Seems character " << this->getName() << " inventory's is full.";
	std::cout << " Let's just put it on the floor." << std::endl;
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
	else
	{
		std::cout << "Character " << this->getName() << " unequiped n* " << idx;
		std::cout << " of their inventory." << std::endl;
		this->addToFloor(*this->_slot[idx]);
		this->_slot[idx] = NULL;
	}
}

void    Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= BAG)
	{
		std::cout << "Use error: use a valid index between 0 and 3." << std::endl;
		return;
	}
	if (this->_slot[idx] != NULL)
	{
		std::cout << this->getName() << " ";
		this->_slot[idx]->use(target);
	}
	else
		std::cout << this->getName() << " does not have anything, in this slot." << std::endl;
}

void    Character::clearFloor()
{
	for (unsigned int i = 0; i < this->_floorIdx; ++i)
    {
        if (this->_floor[i] != NULL)
            delete[] this->_floor;
    }
	this->_floorIdx = 0;
}

void		Character::addToFloor(AMateria &materia)
{
	if ((this->getFloorCapacity() - 1 <= this->getFloorIdx()))
	{
		incrementFloorCapacity(4);
		AMateria** newFloor = new AMateria*[this->getFloorCapacity()];
		for (unsigned int i = 0; i < this->getFloorCapacity() - 4; i++)
			newFloor[i] = _floor[i];
		delete [] _floor;
		AMateria** auxFloor = new AMateria*[this->getFloorCapacity()];
		_floor = auxFloor;
		for (unsigned int i = 0; i < this->getFloorCapacity() - 4; i++)
			_floor[i] = newFloor[i];
		_floor[this->getFloorIdx()] = &materia;
		incrementFloorIdx();
		delete [] newFloor;
	}
	else
	{
		_floor[this->getFloorIdx()] = &materia;
		incrementFloorIdx();
	}
}

unsigned int	Character::getFloorCapacity() const
{
	return (_floorCapacity);
}

unsigned int	Character::getFloorIdx() const
{
	return (_floorIdx);
}

void	Character::incrementFloorCapacity(unsigned int increment)
{
	_floorCapacity += increment;
}

void	Character::incrementFloorIdx()
{
	++_floorIdx;
}

void	Character::printMaterias() const
{
	int idx = 0;
	std::cout << "Character " << this->getName() << " has these elements in";
	std::cout << " their bag:" << std::endl;
	for (int i = 0; i < BAG; ++i)
	{
		if (this->_slot[i])
			std::cout << "Index " << idx << ": " << this->_slot[i]->getType() << std::endl;
		++idx;	
	}
	std::cout << "And there are those elements on the floor:" << std::endl;
	idx = 0;
	if (this->getFloorIdx())

	for (unsigned int i = 0; i < this->getFloorIdx(); ++i)
	{
		if (this->_floor[i] != NULL)
			std::cout << "Index " << idx << ": " << this->_floor[i]->getType() << std::endl;
		++idx;
	}
}