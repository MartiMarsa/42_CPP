/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:31:46 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/10 11:19:56 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>


int main( void )
{
    Point   a(0.0f ,0.0f);
    Point   b(5.0f,0.0f);
    Point   c(0.0f,5.0f);
    Point  point(1.0f, 1.0f);

    if (bsp(a,b,c,point))
        std::cout << "This is in." << std::endl;
    else
        std::cout << "This is out." << std::endl;
    return (0);
}
