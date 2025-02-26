/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:45:24 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/26 13:45:25 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
	Zombie* zn;
    int n;

    if (argc < 2)
    {
        std::cout << "Haha so funny, but provide a number at least." << std::endl;
		return (1);
	}
    n = std::atoi(argv[1]);
    if (n == 0 && argv[1][0] != '0')
	{
        std::cout << "Haha so funny, but provide a CORRECT number at least." << std::endl;
		return (1);
	}
	if (argv[2])
		zn = zombieHorde(n, argv[2]);
	else
		zn = zombieHorde(n, "Tullido");
	for (int i = 0; i < n; ++i)
		zn[i].announce();
	delete[] zn;
	return (0);
}