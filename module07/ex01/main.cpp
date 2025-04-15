/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:36:29 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/14 15:36:31 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    int	array[] = {0,1,2,3,4,5};

	iter(array, 6, hello<int>);
	std::cout << '\n';


	std::string names[] = {"ALBERTO", "PEDRO", "OLIVIA", "ARIANDA", "DANIELLE"};
	iter(names, 5, hello<std::string>);
	std::cout << std::endl;  

	return (0);
}