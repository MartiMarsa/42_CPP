/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:38:27 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/11 15:38:29 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "realType.hpp"

int	main(void)
{
	Base* p = generate();
	Base& ref = *p;

	identify(p);
	identify(ref);
	
	delete p;
	return (0);
}
