/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:26:32 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/25 16:26:35 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    _name = "One-legged zombie";
    std::cout << _name << " was born." << std::endl;
    return ;
}

Zombie::Zombie( std::string name)
{
    this->_name = name;
    std::cout << this->_name << " was born." << std::endl;    
    return ;
}

Zombie::~Zombie()
{
    std::cout << _name << " is more than dead." << std::endl;
    return ;
}

void    Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
