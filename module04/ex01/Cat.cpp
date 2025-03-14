/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:55:57 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/14 15:55:58 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor has been called." << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy-constructor has been called." << std::endl;
    this->_type = other._type;
    this->_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        delete _brain;
        _brain = new Brain(*other._brain);
        this->_type = other._type;
    }
    return (*this);
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat default destructor has been called." << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Meeeeooow Meeeeooow!!!!!!!!" << std::endl;
}

