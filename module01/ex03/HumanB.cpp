/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:38:26 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/26 16:38:28 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weaponType(NULL) {}

HumanB::~HumanB() {}

void    HumanB::attack()
{
    if (_weaponType)
        std::cout << _name << " attack with their " << _weaponType->getType() << std::endl;
    else
		std::cout << _name << " attack with their bare hands " << std::endl;
}

void	HumanB::setWeapon(Weapon &type)
{
	_weaponType = &type;
}