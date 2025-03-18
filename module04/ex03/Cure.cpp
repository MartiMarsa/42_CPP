/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:06:16 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/17 16:06:18 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria(other)
{
   this->_type = "cure"; 
}

Cure    &Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Cure::~Cure() {}

AMateria*	Cure::clone() const
{
	AMateria* cure = new Cure();
	return (cure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

