/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:37:56 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/26 16:37:58 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weaponType(weapon)
{
    return ;
}

HumanA::~HumanA()
{
    return ;
}

void    HumanA::attack()
{
    std::cout << _name << " attack with their " << _weaponType.getType() << std::endl;
}
