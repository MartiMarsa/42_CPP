/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:18:05 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/11 19:18:07 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int	a = 6;
	int b = 8;
	char c = 'c';
	char d = 'd';

	std::cout << "a = " << a << " b = " << b << "\n";
	std::cout << "Then we aply swap()\n"; 
	swap (a, b);
	std::cout << "a = " << a << " b = " << b << "\n";

	std::cout << "c = " << c << " d = " << d << "\n";
	std::cout << "Then we aply swap()\n";
	swap (c, d);
	std::cout << "c = " << c << " d = " << d << "\n";
	return (0);
}
