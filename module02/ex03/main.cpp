/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:31:46 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/01 10:31:50 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>


int main( void )
{
    Point   a(0,0);
    Point   b(7,2);
    Point   c(4,-4);
    Point  point(3,2);

    if (bsp(a,b,c,point))
        std::cout << "This is in." << std::endl;
    else
        std::cout << "This is out." << std::endl;
    return (0);
}