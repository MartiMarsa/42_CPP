/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:36:56 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/26 16:36:58 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

int main(void)
{
    Weapon w = Weapon("raw tomatoe");
    HumanA  carlos = HumanA("Carlos", w);

    carlos.attack();
    std::cout << "Someone has thrown you a " << w.getType() << ". Fuck off" << std::endl;

    return (0);
}