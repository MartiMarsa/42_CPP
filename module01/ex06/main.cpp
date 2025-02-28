/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:50:38 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/28 09:50:43 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	fussy;

	if (argc != 2)
	{
		std::cout << "Please, insert just one command: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}
	fussy.complain(argv[1]);
	return (0);
}
