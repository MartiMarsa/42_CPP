/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:01:48 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/05 16:01:49 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed ix = a.getX();
	Fixed iy = a.getY();
	Fixed jx = b.getX();
	Fixed jy = b.getY();
	Fixed kx = c.getX();
	Fixed ky = c.getY();
	Fixed pointx = point.getX();
	Fixed pointy = point.getY();
	
    Fixed denominator = (jx - ix) * (ky - iy) - 
                        (jy - iy) * (kx - ix);

    Fixed alpha = ((pointx - ix) * (ky - iy) - 
                   (pointy - iy) * (kx - ix)) / denominator;

    Fixed beta = ((jx - ix) * (pointy - iy) - 
                  (jy - iy) * (pointx - ix)) / denominator;

    Fixed gamma = Fixed(1) - alpha - beta;

    return (alpha > Fixed(0) && beta > Fixed(0) && gamma > Fixed(0));
}
