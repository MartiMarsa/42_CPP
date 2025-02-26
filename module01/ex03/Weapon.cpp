/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:37:21 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/26 16:37:23 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->_type = type;
    return ;
}

Weapon::~Weapon()
{
    return ;
}

const std::string&	Weapon::getType()
{
    return (_type);
}

void				Weapon::setType(std::string type)
{
    this->_type = type;
}