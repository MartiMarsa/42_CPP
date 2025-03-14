/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:56:59 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/14 15:57:00 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor has been called." << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy-constructor has been called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat default destructor has been called." << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "Maybe I'm a cat or something like that." << std::endl;
}
