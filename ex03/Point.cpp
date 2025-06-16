/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:12:35 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/16 14:06:31 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief	Default constructor for Point class.
 * Initializes the point at the origin (0, 0).
 */
Point::Point() : x(0), y(0)
{}

/**
 * @brief	Constructor that initializes the point with given x and y coordinates.
 */
Point::Point(float a, float b) : x(a), y(b)
{}

/**
 * @brief	Copy constructor for Point class.
 * Initializes the point with the coordinates of another point.
 * 
 * @param	origin The point to copy from.
 */
Point::Point(Point &origin) : x(origin.x), y(origin.y)
{}

/**
 * @brief	Copy assignment operator for Point class.
 * 
 * @param	other The point to assign from.
 * @return	A reference to the current object.
 */
Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

/**
 * @brief	Destructor for Point class.
 */
Point::~Point()
{}

/**
 * @brief	Returns the x-coordinate of the point.
 * 
 * @return	The x-coordinate as a Fixed object.
 */
Fixed	Point::getX() const
{
	return (x);
}

/**
 * @brief	Returns the y-coordinate of the point.
 * 
 * @return	The y-coordinate as a Fixed object.
 */
Fixed	Point::getY() const
{
	return (y);
}
