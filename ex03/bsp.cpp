/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:28:02 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/03 11:32:50 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/**
 * @brief	Calculates the double area of a triangle formed by three points.
 * 
 * @param	a The first vertex of the triangle.
 * @param	b The second vertex of the triangle.
 * @param	c The third vertex of the triangle.
 * @return	The absolute value of the double area of the triangle.
 */
static Fixed	tri_area(Point const &a, Point const &b, Point const &c)
{
	Fixed	res = (a.getX() * (b.getY() - c.getY()))
				+ (b.getX() * (c.getY() - a.getY()))
				+ (c.getX() * (a.getY() - b.getY()));

	if (res < 0)
		return (res * Fixed(-1));
	return (res);
}

/**
 * @brief	Determines if a point is inside a triangle defined by three points.
 * 
 * @param	a The first vertex of the triangle.
 * @param	b The second vertex of the triangle.
 * @param	c The third vertex of the triangle.
 * @param	point The point to check.
 * @return	True if the point is inside the triangle, false otherwise.
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	total, areaABP, areaACP, areaBCP;

	total = tri_area(a, b, c);
	areaABP = tri_area(a, b, point);
	areaACP = tri_area(a, c, point);
	areaBCP = tri_area(b, c, point);

	return ((areaABP + areaACP + areaBCP == total)
		&& !(areaABP == 0 || areaACP == 0 || areaBCP == 0));
}
