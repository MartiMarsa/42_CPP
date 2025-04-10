/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:06:54 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/10 19:06:57 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int		main(void)
{
	Data* account1 = new Data;
	account1->rank = 1;
	account1->balance = 100.50;
	account1->currency = '$';

	uintptr_t	SerialA1 = Serializer::serialize(account1);
	Data*		DeSerialA1 = Serializer::deserialize(SerialA1);

	std::cout << "Account num 1: " << *account1 << "Pointer: " << account1 << std::endl;
	std::cout << "\nSerialized-> " << SerialA1 << std::endl;
	std::cout << "\nProcess backwards->\n" << *DeSerialA1 << "Pointer: " << DeSerialA1;
	std::cout << std::endl;

	delete account1;

	return (0);
}
