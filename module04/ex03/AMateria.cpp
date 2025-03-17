/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:40:59 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/14 19:41:02 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Chaos") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other)
{
    *this = other;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
    return (_type);
}

void	AMateria::use(ICharacter &target)
{
    std::cout << "* " << target.getName() << " it's not affected by this whatever";
    std::cout << " it is" << std::endl;
}

