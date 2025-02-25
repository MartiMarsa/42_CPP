/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:27:08 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/25 16:27:14 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ( void )
{
	Zombie z1;
	Zombie z2("Undertaker");
	Zombie* z3 = newZombie("Buthcer");

	z1.announce();
	z2.announce();
	z3->announce();
	randomChump("Piece of shit");

	delete z3;	

	return (0);
}
