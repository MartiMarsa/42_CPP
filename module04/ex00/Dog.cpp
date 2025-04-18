/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:56:06 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/14 15:56:07 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor has been called." << std::endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy-constructor has been called." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog default destructor has been called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "WOOooooooOOOffff wooooOOOffff!!!!!!!!" << std::endl;
}
